%option noyywrap
%{
    #include <stdlib.h>
    #include <iostream>
    #include <string.h>
    #include "compiler.tab.h"
    #include "compiler.h"
    void yyerror(const char *msg);
    int lineNo=1;
    int colNo=1;
%}

%x COMMENT

%%
[/]{2}.*             { colNo++; }
"/*"                 { BEGIN(COMMENT); }
<COMMENT>"*/"        { BEGIN(INITIAL); }
<COMMENT>.|\n        { 
                        if(yytext[0]=='\n')
                        {
                            lineNo++;
                            colNo=1;
                        }
                        else
                            colNo++;
                     }
[ \t]                { 
                        colNo++;
                     }

int                  { colNo+=3; return INT; }
float                { colNo+=5; return FLOAT; }
double               { colNo+=6; return DOUBLE; }
return               { colNo+=6; return RETURN; }
if                   { colNo+=2; return IF; }
else                 { colNo+=4; return ELSE; }
while                { colNo+=5; return WHILE; }
printf               { colNo+=6; return PRINTF; }
scanf                { colNo+=5; return SCANF; }
run                  { return RUN;}
\".*\"               { 
                        colNo+=strlen(yytext); 
                        yylval.stringVal=new char[strlen(yytext)-1];
                        strncpy(yylval.stringVal,yytext+1,strlen(yytext)-2);
                        return STRING;
                     }

[-()<>=+*/;,.{}]     { colNo++; return yytext[0]; }
"=="                 { colNo+=2; return EQ; }
"!="                 { colNo+=2; return NE; }
"<="                 { colNo+=2; return LE; }
">="                 { colNo+=2; return GE; }

[a-zA-Z][a-zA-Z0-9]* { 
                        yylloc.first_line=lineNo;
                        yylloc.first_column=colNo;
                        colNo+=strlen(yytext);
                        yylval.key=new std::string(yytext);
                        return IDENTIF;
                     }
[a-zA-Z0-9_]+\.txt     { yylval.key=new std::string(yytext);return FILENAME; } 
[+-]?[0-9]+          { 
                        yylloc.first_line=lineNo;
                        yylloc.first_column=colNo;
                        colNo+=strlen(yytext);
                        yylval.intVal=atoi(yytext);
                        long long int a=atoll(yytext);
                        if(a>2147483647 || a<-2147483647)
                            yyerror("Integer overflow");
                        return INT_VALUE;
                    }
[+-]?[0-9]+\.[0-9]+[fF] { 
                            yylloc.first_line=lineNo;
                            yylloc.first_column=colNo;
                            colNo+=strlen(yytext);
                            yylval.floatVal=atof(yytext);
                            double a=atof(yytext);
                            if(a>340282346638528859811704183484516925440.0000000000000000  || a<-340282346638528859811704183484516925440.0000000000000000 )
                                yyerror("Float overflow");
                            return FLOAT_VALUE;
                        }
[+-]?[0-9]+\.[0-9]+ { 
                        yylloc.first_line=lineNo;
                        yylloc.first_column=colNo;
                        colNo+=strlen(yytext);
                        yylval.doubleVal=atof(yytext);
                        return DOUBLE_VALUE;
                    }
"\n"                 { 
                        lineNo++;
                        colNo=1;
                     }
"\r\n"              { 
                        lineNo++;
                        colNo=1;
                     }

.                    { 
                        colNo++;
                        yyerror("Unknown character");
                        return ERROR;
                     }
%%