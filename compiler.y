%locations

%{
    #include "compiler.h"
    #include <cstdarg>
    #include <string.h>

    extern FILE * yyin;

    nodeType *nodOper (int oper, int nops, ...);
    nodeType *nodId (std::string id);
    nodeType *nodConst (ValType valType, int intVal, float floatVal, double doubleVal);
    nodeType *nodConst (char* strVal);
    void freeNode (nodeType *p);
    
    Value eval (nodeType *p);

    int yylex();
    int yyerror(const char *msg);

    std::map<std::string, SymbolTable> symbolTable;


%}

%code requires
{
    #include "compiler.h"
}

%union {
    int intVal;
    float floatVal;
    double doubleVal;
    ValType valType;
    std::string* key;
    nodeType *nodPtr;
    std::string* func;
    char* stringVal;
}

%token ERROR RUN
%token INT FLOAT DOUBLE
%token IF ELSE WHILE RETURN 
%token EQ NE LT LE GT GE
%token SCANF PRINTF
%token <key> IDENTIF
%token <intVal> INT_VALUE
%token <floatVal> FLOAT_VALUE
%token <doubleVal> DOUBLE_VALUE
%token <stringVal> STRING
%token <key> FILENAME

%left ','
%left EQ NE LT LE GT GE '<' '>'
%left '='
%left '+' '-'
%left '*' '/'
%left '(' ')'
%nonassoc IFX
%nonassoc ELSE

%type <nodPtr> function statement statements expression

%%
program: units
    ;

units: unit
    |   unit units
    ;

unit: statement                                                 { eval($1);}
    | function                                                  { eval($1);}
    ;
function: INT IDENTIF paramadecl '{' statements '}'             { $$ = $5;}
    |     FLOAT IDENTIF paramadecl '{' statements '}'           { $$ = $5;}
    |     DOUBLE IDENTIF paramadecl '{' statements '}'          { $$ = $5;}
    |     INT IDENTIF paramadecl '{' '}'                        {}
    |     FLOAT IDENTIF paramadecl '{' '}'                      {}
    |     DOUBLE IDENTIF paramadecl '{' '}'                     {}
    ;
paramadecl:  '(' declarations ')' 
    |        '(' ')'    
    ;
declarations: declaration
    |         declaration ',' declarations
    ;
declaration: INT IDENTIF
    |        FLOAT IDENTIF
    |        DOUBLE IDENTIF
    ;
statements:  statement                                              { $$ = $1;}
    |        statement statements                                   { $$ = nodOper(';', 2, $1, $2);}
    ;
statement: INT IDENTIF ';'                                          { 
                                                                        symbolTable[*$2].type = (ValType)1; 
                                                                        symbolTable[*$2].intValue = 0;
                                                                        $$ = nodOper('=', 2, nodId(*$2), nodConst((ValType)1, 0, 0.0, 0.0));
                                                                    }
    |      FLOAT IDENTIF ';'                                        { 
                                                                        symbolTable[*$2].type = (ValType)2; 
                                                                        symbolTable[*$2].floatValue = 0.0;
                                                                        $$ = nodOper('=', 2, nodId(*$2), nodConst((ValType)2, 0, 0.0, 0.0));
                                                                    }
    |      DOUBLE IDENTIF ';'                                       { 
                                                                        symbolTable[*$2].type = (ValType)3; 
                                                                        symbolTable[*$2].doubleValue = 0.0;
                                                                        $$ = nodOper('=', 2, nodId(*$2), nodConst((ValType)3, 0, 0.0, 0.0));
                                                                    }
    |      INT IDENTIF '=' expression ';'                           { 
                                                                        symbolTable[*$2].type = (ValType)1; 
                                                                        symbolTable[*$2].intValue = 0;
                                                                        $$ = nodOper('=', 2, nodId(*$2), $4);
                                                                    }
    |      FLOAT IDENTIF '=' expression ';'                         { 
                                                                        symbolTable[*$2].type = (ValType)2; 
                                                                        symbolTable[*$2].floatValue = 0.0;
                                                                        $$ = nodOper('=', 2, nodId(*$2), $4);
                                                                    }
    |      DOUBLE IDENTIF '=' expression ';'                        { 
                                                                        symbolTable[*$2].type = (ValType)3; 
                                                                        symbolTable[*$2].doubleValue = 0.0;
                                                                        $$ = nodOper('=', 2, nodId(*$2), $4);
                                                                    }
    |      '{' statements '}'                                       { $$ = $2;}
    |      IF '(' expression ')' statement                          { $$ = nodOper(IF, 2, $3, $5); }
    |      IF '(' expression ')' statement ELSE statement           { $$ = nodOper(IF, 3, $3, $5, $7);}
    |      WHILE '(' expression ')' statement                       { $$ = nodOper(WHILE, 2, $3, $5);}
    |      RETURN expression ';'                                    { $$ = nodOper(RETURN, 1, $2);}
    |      expression ';'                                           { $$ = $1; }
    |      ';'                                                      { 
                                                                        $$ = nodConst((ValType)1, 0, 0.0, 0.0);
                                                                    }
    |      SCANF '(' IDENTIF ')' ';'                                { $$ = nodOper(SCANF, 1, nodId(*$3));}
    |      PRINTF '(' STRING ')' ';'                                { $$ = nodOper(PRINTF, 1, nodConst($3)); }
    |      PRINTF '(' STRING ',' IDENTIF ')' ';'                    { $$ = nodOper(PRINTF, 2, nodConst($3), nodId(*$5)); }
    |      RUN FILENAME                                             { 
                                                                        std::string filename=*$2;
                                                                        FILE* fp=fopen(filename.c_str(),"r");
                                                                        yyin=fp;
                                                                        yyparse();
                                                                    }
    ;
expression: IDENTIF                                                 { $$ = nodId(*$1); }
    |       INT_VALUE                                               { $$ = nodConst((ValType)1, $1, 0.0, 0.0); }
    |       FLOAT_VALUE                                             { $$ = nodConst((ValType)2, 0, $1, 0.0); }
    |       DOUBLE_VALUE                                            { $$ = nodConst((ValType)3, 0, 0.0, $1); }
    |       expression '+' expression                               { $$ = nodOper('+', 2, $1, $3);}
    |       expression '-' expression                               { $$ = nodOper('-', 2, $1, $3);}
    |       expression '*' expression                               { $$ = nodOper('*', 2, $1, $3);}
    |       expression '/' expression                               { $$ = nodOper('/', 2, $1, $3);}
    |       expression '=' expression                               { $$ = nodOper('=', 2, $1, $3); }
    |       '(' expression ')'                                      { $$ = $2; }
    |       expression EQ expression                                { $$ = nodOper(EQ, 2, $1, $3); }
    |       expression NE expression                                { $$ = nodOper(NE, 2, $1, $3); }
    |       expression LT expression                                { $$ = nodOper(LT, 2, $1, $3); }
    |       expression LE expression                                { $$ = nodOper(LE, 2, $1, $3); }
    |       expression GT expression                                { $$ = nodOper(GT, 2, $1, $3); }
    |       expression GE expression                                { $$ = nodOper(GE, 2, $1, $3); }
    |       expression '<' expression                               { $$ = nodOper('<', 2, $1, $3); }
    |       expression '>' expression                               { $$ = nodOper('>', 2, $1, $3); }
    |       '(' INT ')' expression                                  { $$ = nodOper(INT, 1, $4); }
    |       '(' FLOAT ')' expression                                { $$ = nodOper(FLOAT, 1, $4); }
    |       '(' DOUBLE ')' expression                               { $$ = nodOper(DOUBLE, 1, $4); }
    ;

%%

#define SIZEOF_NONDETYPE ((char *)&p->con - (char *)p)

nodeType *nodConst (char* strVal)
{
    nodeType *p;
    size_t nodeSize;

    nodeSize = SIZEOF_NONDETYPE + sizeof(conNodeType);
    if((p=new nodeType[nodeSize]) == NULL)
    {
        yyerror("out of memory");
    }
    p->type = typeCon;
    p->con.type = (ValType)4;
    p->con.stringValue = new char[strlen(strVal)+1];
    strcpy(p->con.stringValue, strVal);
    return p;
}

nodeType *nodConst (ValType valType, int intVal, float floatVal, double doubleVal)
{
    nodeType *p;
    size_t nodeSize;

    nodeSize = SIZEOF_NONDETYPE + sizeof(conNodeType);
    if((p=new nodeType[nodeSize]) == NULL)
    {
        yyerror("out of memory");
    }
    p->type = typeCon;
    p->con.type = valType;
    switch(valType)
    {
        case (ValType)1:
            p->con.intValue = intVal;
            p->con.type = (ValType)1;
            break;
        case (ValType)2:
            p->con.floatValue = floatVal;
            p->con.type = (ValType)2;
            break;
        case (ValType)3:
            p->con.doubleValue = doubleVal;
            p->con.type = (ValType)3;
            break;
        default:
            yyerror("internal error: bad value type");
            break;
    }
    return p;
}

nodeType *nodId (std::string id)
{
    nodeType *p;
    size_t nodeSize;
    

    nodeSize = SIZEOF_NONDETYPE + sizeof(idNodeType);
    if((p=new nodeType[nodeSize]) == NULL)
    {
        yyerror("out of memory");
    }
    p->type = typeId;
    p->id.name =new std::string(id);
    return p;
}

nodeType *nodOper (int oper, int nops, ...)
{
    va_list ap;
    nodeType *p;
    size_t nodeSize;
    int i;

    nodeSize = SIZEOF_NONDETYPE + sizeof(oprNodeType) + (nops-1)*sizeof(nodeType *);
    if((p=new nodeType[nodeSize]) == NULL)
    {
        yyerror("out of memory");
    }
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for(i=0; i<nops; i++)
    {
        p->opr.op[i] = va_arg(ap, nodeType *);
    }
    va_end(ap);
    return p;
}

void freeNode (nodeType *p)
{
    int i;

    if(!p)
    {
        return;
    }
    if(p->type == typeId)
    {
        delete p->id.name;
    }
    else if(p->type == typeOpr)
    {
        for(i=0; i<p->opr.nops; i++)
        {
            freeNode(p->opr.op[i]);
        }
    }
    delete p;
}

Value eval(nodeType *p)
{
    if(!p)
    {
        return Value((int)0);
    }
    Value val,rval;
    switch (p->type)
    {
        case typeCon:
            switch (p->con.type)
            {
                case (ValType)1:
                    return Value((int)p->con.intValue);
                    break;
                case (ValType)2:
                    return Value((float)p->con.floatValue);
                    break;
                case (ValType)3:
                    return Value((double)p->con.doubleValue);
                    break;
                case (ValType)4:
                    return Value(p->con.stringValue);
                default:
                    yyerror("internal error, bad value type");
                    break;
            }
            break;
        case typeId:
            if(symbolTable.find(*(p->id.name)) == symbolTable.end())
            {
                yyerror("undefined variable");
            }
            else
            {
               switch (symbolTable[*(p->id.name)].type)
                {
                    case (ValType)1:
                        val=Value(symbolTable[*(p->id.name)].intValue, symbolTable[*(p->id.name)].type);
                        break;
                    case (ValType)2:
                        val=Value(symbolTable[*(p->id.name)].floatValue, symbolTable[*(p->id.name)].type);
                        break;
                    case (ValType)3:
                        val=Value(symbolTable[*(p->id.name)].doubleValue, symbolTable[*(p->id.name)].type);
                        break;
                }
                if(!symbolTable[*(p->id.name)].intValue && !symbolTable[*(p->id.name)].floatValue && !symbolTable[*(p->id.name)].doubleValue)
                    return val;
                switch (val.type)
                {
                    case (ValType)1:
                        if(val.intValue)
                            return val;
                        yyerror("type mismatch");
                        break;
                    case (ValType)2:
                        if(val.floatValue)
                            return val;
                        yyerror("type mismatch");
                        break;
                    case (ValType)3:
                        if(val.doubleValue)
                            return val;
                        yyerror("type mismatch");
                        break;
                    default:
                        yyerror("internal error, bad value type");
                        break;
                }
            }
            break;
        case typeOpr:
            switch (p->opr.oper)
            {
                case IF:
                    val = eval(p->opr.op[0]);
                    std::cout<<"IF: "<<val.boolValue<<std::endl;
                    if(val.boolValue)
                    {
                        rval = eval(p->opr.op[1]);
                        return rval;
                    }
                    else if(p->opr.nops > 2)
                    {
                        rval = eval(p->opr.op[2]);
                        return rval;
                    }
                    break;
                case WHILE:
                    while(eval(p->opr.op[0]).boolValue)
                    {
                        rval = eval(p->opr.op[1]);
                    }
                    return Value((int)0);
                    break;
                case PRINTF:
                    if(p->opr.nops > 1)
                    {
                        val = eval(p->opr.op[1]);
                        switch(val.type)
                        {
                            case (ValType)1:
                                printf(p->opr.op[0]->con.stringValue, eval(p->opr.op[1]).intValue);
                                break;
                            case (ValType)2:
                                printf(p->opr.op[0]->con.stringValue, eval(p->opr.op[1]).floatValue);
                                break;
                            case (ValType)3:
                                printf(p->opr.op[0]->con.stringValue, eval(p->opr.op[1]).doubleValue);
                                break;
                            default:
                                yyerror("internal error, bad value type");
                                break;
                        }
                    }
                    else
                    {
                        printf("%s",p->opr.op[0]->con.stringValue);
                    }
                    printf("\n");
                    return Value((int)0);
                    break;
                case SCANF:
                    if(symbolTable.find(*(p->opr.op[0]->id.name)) == symbolTable.end())
                    {
                        yyerror("undefined variable");
                        return Value((int)0);
                    }
                    else {
                    std::cout<<"SCANF: "<<*(p->opr.op[0]->id.name)<<std::endl;
                        switch(symbolTable[*(p->opr.op[0]->id.name)].type)
                        {
                            case (ValType)1:
                                std::cin>>symbolTable[*(p->opr.op[0]->id.name)].intValue;
                                break;
                            case (ValType)2:
                                std::cin>>symbolTable[*(p->opr.op[0]->id.name)].floatValue;
                                break;
                            case (ValType)3:
                                std::cin>>symbolTable[*(p->opr.op[0]->id.name)].doubleValue;
                                break;
                            default:
                                yyerror("internal error, bad value type");
                                break;
                        }
                    }
                    break;
                case RETURN:
                    return eval(p->opr.op[0]);
                    break;
                case '=':
                    rval = eval(p->opr.op[1]);
                    if(p->opr.op[0]->type != typeId)
                    {
                        yyerror("lvalue required as left operand of assignment");
                        return Value((int)0);
                    }
                    if(symbolTable.find(*(p->opr.op[0]->id.name)) == symbolTable.end())
                    {
                        yyerror("undefined variable");
                        return Value((int)0);
                    }
                    if(symbolTable[*(p->opr.op[0]->id.name)].type != rval.type)
                    {
                        yyerror("type mismatch");
                        return Value((int)0);
                    }
                    switch (rval.type)
                    {
                        case (ValType)1:
                            symbolTable[*(p->opr.op[0]->id.name)].intValue = rval.intValue;
                            break;
                        case (ValType)2:
                            symbolTable[*(p->opr.op[0]->id.name)].floatValue = rval.floatValue;
                            break;
                        case (ValType)3:
                            symbolTable[*(p->opr.op[0]->id.name)].doubleValue = rval.doubleValue;
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    } 
                    
                    break;
                case '+':
                    val = eval(p->opr.op[0]);
                    rval = eval(p->opr.op[1]);
                    if(val.type != rval.type)
                    {
                        yyerror("type mismatch");
                        return Value((int)0);
                    }
                    switch (val.type)
                    {
                        case (ValType)1:
                            return Value(val.intValue + rval.intValue);
                            break;
                        case (ValType)2:
                            return Value(val.floatValue + rval.floatValue);
                            break;
                        case (ValType)3:
                            return Value(val.doubleValue + rval.doubleValue);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case '-':
                    val=eval(p->opr.op[0]);
                    rval=eval(p->opr.op[1]);
                    if(val.type != rval.type)
                    {
                        yyerror("type mismatch");
                        return Value((int)0);
                    }
                    switch (val.type)
                    {
                        case (ValType)1:
                            return Value(val.intValue - rval.intValue);
                            break;
                        case (ValType)2:
                            return Value(val.floatValue - rval.floatValue);
                            break;
                        case (ValType)3:
                            return Value(val.doubleValue - rval.doubleValue);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case '*':
                    val=eval(p->opr.op[0]);
                    rval=eval(p->opr.op[1]);
                    if(val.type != rval.type)
                    {
                        yyerror("type mismatch");
                        return Value((int)0);
                    }
                    switch (val.type)
                    {
                        case (ValType)1:
                            return Value(val.intValue * rval.intValue);
                            break;
                        case (ValType)2:
                            return Value(val.floatValue * rval.floatValue);
                            break;
                        case (ValType)3:
                            return Value(val.doubleValue * rval.doubleValue);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case '/':
                    val=eval(p->opr.op[0]);
                    rval=eval(p->opr.op[1]);
                    if(val.type != rval.type)
                    {
                        yyerror("type mismatch");
                        return Value((int)0);
                    }
                    switch (val.type)
                    {
                        case (ValType)1:
                            if(rval.intValue == 0)
                            {
                                yyerror("division by zero");
                            }
                            return Value(val.intValue / rval.intValue);
                            break;
                        case (ValType)2:
                            if(rval.floatValue == 0.0)
                            {
                                yyerror("division by zero");
                            }
                            return Value(val.floatValue / rval.floatValue);
                            break;
                        case (ValType)3:
                            if(rval.doubleValue == 0.0)
                            {
                                yyerror("division by zero");
                            }
                            return Value(val.doubleValue / rval.doubleValue);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case EQ:
                    val = eval(p->opr.op[0]);  
                    rval = eval(p->opr.op[1]);
                    if(val.type != rval.type)
                    {
                        yyerror("type mismatch");
                        return Value((int)0);
                    }
                    switch (val.type)
                    {
                        case (ValType)1:
                            std::cout<<"EQ: "<<val.intValue<<" "<<rval.intValue<<std::endl;
                            if(val.intValue == rval.intValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)2:
                            if(val.floatValue == rval.floatValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)3:
                            if(val.doubleValue == rval.doubleValue)
                                return Value(true);
                            return Value(false);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case NE:
                    val = eval(p->opr.op[0]);
                    rval = eval(p->opr.op[1]);
                    if(val.type != rval.type)
                    {
                        yyerror("type mismatch");
                        return Value((int)0);
                    }
                    switch (val.type)
                    {
                        case (ValType)1:
                            if(val.intValue != rval.intValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)2:
                            if(val.floatValue != rval.floatValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)3:
                            if(val.doubleValue != rval.doubleValue)
                                return Value(true);
                            return Value(false);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case LT:
                    val = eval(p->opr.op[0]);
                    rval = eval(p->opr.op[1]);
                    if(val.type != rval.type)
                    {
                        yyerror("type mismatch");
                        return Value((int)0);
                    }
                    switch (val.type)
                    {
                        case (ValType)1:
                            if(val.intValue < rval.intValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)2:
                            if(val.floatValue < rval.floatValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)3:
                            if(val.doubleValue < rval.doubleValue)
                                return Value(true);
                            return Value(false);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case LE:
                    val = eval(p->opr.op[0]);
                    rval = eval(p->opr.op[1]);
                    if(val.type != rval.type)
                    {
                        yyerror("type mismatch");
                        return Value((int)0);
                    }
                    switch (val.type)
                    {
                        case (ValType)1:
                            if(val.intValue <= rval.intValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)2:
                            if(val.floatValue <= rval.floatValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)3:
                            if(val.doubleValue <= rval.doubleValue)
                                return Value(true);
                            return Value(false);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case GT:
                    val = eval(p->opr.op[0]);
                    rval = eval(p->opr.op[1]);
                    if(val.type != rval.type)
                    {
                        yyerror("type mismatch");
                        return Value((int)0);
                    }
                    switch (val.type)
                    {
                        case (ValType)1:
                            if(val.intValue > rval.intValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)2:
                            if(val.floatValue > rval.floatValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)3:
                            if(val.doubleValue > rval.doubleValue)
                                return Value(true);
                            return Value(false);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case GE:
                    val = eval(p->opr.op[0]);
                    rval = eval(p->opr.op[1]);
                    if(val.type != rval.type)
                    {
                        yyerror("type mismatch");
                        return Value((int)0);
                    }
                    switch (val.type)
                    {
                        case (ValType)1:
                            if(val.intValue >= rval.intValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)2:
                            if(val.floatValue >= rval.floatValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)3:
                            if(val.doubleValue >= rval.doubleValue)
                                return Value(true);
                            return Value(false);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case '<':
                    val = eval(p->opr.op[0]);
                    rval = eval(p->opr.op[1]);
                    if(val.type != rval.type)
                    {
                        yyerror("type mismatch");
                        return Value((int)0);
                    }
                    switch(val.type)
                    {
                        case (ValType)1:
                            if(val.intValue < rval.intValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)2:
                            if(val.floatValue < rval.floatValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)3:
                            if(val.doubleValue < rval.doubleValue)
                                return Value(true);
                            return Value(false);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case '>':
                    val = eval(p->opr.op[0]);
                    rval = eval(p->opr.op[1]);
                    if(val.type != rval.type)
                    {
                        yyerror("type mismatch");
                    }
                    switch(val.type)
                    {
                        case (ValType)1:
                            if(val.intValue > rval.intValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)2:
                            if(val.floatValue > rval.floatValue)
                                return Value(true);
                            return Value(false);
                            break;
                        case (ValType)3:
                            if(val.doubleValue > rval.doubleValue)
                                return Value(true);
                            return Value(false);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case INT:
                    val = eval(p->opr.op[0]);
                    switch (val.type)
                    {
                        case (ValType)1:
                            return Value((int)val.intValue);
                            break;
                        case (ValType)2:
                            return Value((int)val.floatValue);
                            break;
                        case (ValType)3:
                            return Value((int)val.doubleValue);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case FLOAT:
                    val = eval(p->opr.op[0]);
                    switch (val.type)
                    {
                        case (ValType)1:
                            return Value((float)val.intValue);
                            break;
                        case (ValType)2:
                            return Value((float)val.floatValue);
                            break;
                        case (ValType)3:
                            return Value((float)val.doubleValue);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case DOUBLE:
                    val = eval(p->opr.op[0]);
                    switch (val.type)
                    {
                        case (ValType)1:
                            return Value((double)val.intValue);
                            break;
                        case (ValType)2:
                            return Value((double)val.floatValue);
                            break;
                        case (ValType)3:
                            return Value((double)val.doubleValue);
                            break;
                        default:
                            yyerror("internal error, bad value type");
                            break;
                    }
                    break;
                case ';':
                    eval(p->opr.op[0]);
                    return eval(p->opr.op[1]);
                    break;
                default:
                    yyerror("internal error, bad node");
                    break;
            }
            break;
    }
    return Value((int)0);
}

int main(int argc, char **argv)
{
    yyparse();
    std::cout<<"Program compiled successfully!"<<std::endl;
    //print variables
    std::cout<<"Variables:"<<std::endl;
    for(auto it = symbolTable.begin(); it != symbolTable.end(); ++it)
    {
        std::cout<<it->first<<" ";
        switch (it->second.type)
        {
            case (ValType)1:
                std::cout<<"int "<<it->second.intValue<<std::endl;
                break;
            case (ValType)2:
                std::cout<<"float "<<it->second.floatValue<<std::endl;
                break;
            case (ValType)3:
                std::cout<<"double "<<it->second.doubleValue<<std::endl;
                break;
            default:
                yyerror("internal error, bad value type");
                break;
        }
    }
    return 0;
}

int yyerror(const char *msg)
{
	std::cout<<"EROARE: "<<msg<<std::endl;	
	exit (1);
}
