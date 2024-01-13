/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "compiler.y"

    #include "compiler.h"
    #include <cstdarg>
    #include <string.h>

    nodeType *nodOper (int oper, int nops, ...);
    nodeType *nodId (std::string id);
    nodeType *nodConst (ValType valType, int intVal, float floatVal, double doubleVal);
    nodeType *nodConst (char* strVal);
    void freeNode (nodeType *p);
    
    Value eval (nodeType *p);

    int yylex();
    int yyerror(const char *msg);

    std::map<std::string, SymbolTable> symbolTable;



#line 92 "compiler.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "compiler.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ERROR = 3,                      /* ERROR  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_DOUBLE = 6,                     /* DOUBLE  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_EQ = 11,                        /* EQ  */
  YYSYMBOL_NE = 12,                        /* NE  */
  YYSYMBOL_LT = 13,                        /* LT  */
  YYSYMBOL_LE = 14,                        /* LE  */
  YYSYMBOL_GT = 15,                        /* GT  */
  YYSYMBOL_GE = 16,                        /* GE  */
  YYSYMBOL_SCANF = 17,                     /* SCANF  */
  YYSYMBOL_PRINTF = 18,                    /* PRINTF  */
  YYSYMBOL_IDENTIF = 19,                   /* IDENTIF  */
  YYSYMBOL_INT_VALUE = 20,                 /* INT_VALUE  */
  YYSYMBOL_FLOAT_VALUE = 21,               /* FLOAT_VALUE  */
  YYSYMBOL_DOUBLE_VALUE = 22,              /* DOUBLE_VALUE  */
  YYSYMBOL_STRING = 23,                    /* STRING  */
  YYSYMBOL_24_ = 24,                       /* ','  */
  YYSYMBOL_25_ = 25,                       /* '<'  */
  YYSYMBOL_26_ = 26,                       /* '>'  */
  YYSYMBOL_27_ = 27,                       /* '='  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_IFX = 34,                       /* IFX  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_program = 39,                   /* program  */
  YYSYMBOL_units = 40,                     /* units  */
  YYSYMBOL_unit = 41,                      /* unit  */
  YYSYMBOL_function = 42,                  /* function  */
  YYSYMBOL_paramadecl = 43,                /* paramadecl  */
  YYSYMBOL_declarations = 44,              /* declarations  */
  YYSYMBOL_declaration = 45,               /* declaration  */
  YYSYMBOL_statements = 46,                /* statements  */
  YYSYMBOL_statement = 47,                 /* statement  */
  YYSYMBOL_expression = 48                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   391

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    30,    28,    24,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      25,    27,    26,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    63,    63,    66,    67,    70,    71,    73,    74,    75,
      76,    77,    78,    80,    81,    83,    84,    86,    87,    88,
      90,    91,    93,    98,   103,   108,   113,   118,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ERROR", "INT",
  "FLOAT", "DOUBLE", "IF", "ELSE", "WHILE", "RETURN", "EQ", "NE", "LT",
  "LE", "GT", "GE", "SCANF", "PRINTF", "IDENTIF", "INT_VALUE",
  "FLOAT_VALUE", "DOUBLE_VALUE", "STRING", "','", "'<'", "'>'", "'='",
  "'+'", "'-'", "'*'", "'/'", "'('", "')'", "IFX", "'{'", "'}'", "';'",
  "$accept", "program", "units", "unit", "function", "paramadecl",
  "declarations", "declaration", "statements", "statement", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     148,   -14,     3,    30,   -15,    23,    39,    24,    31,   -32,
     -32,   -32,   -32,   188,   169,   -32,    73,   -32,   148,   -32,
     -32,   200,    37,    88,    89,    39,    39,   227,    60,    64,
      61,    62,    67,    -1,   103,   104,   111,   106,   169,   -32,
     -32,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,   -32,    39,    -2,   -32,   108,    39,
     -32,   115,    39,   -32,   116,   335,   358,   -32,   123,    29,
      39,    39,    39,   -32,   -21,   -18,    -4,   -32,   -32,    55,
      55,    55,    55,    55,    55,    55,    55,   110,     4,     4,
     -32,   -32,   254,   141,   142,   152,   -32,   139,   153,    71,
     281,    92,   308,   127,   169,   169,   144,   163,   147,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   113,   -32,   159,
     -32,   -32,   160,   -32,   -32,   161,   190,   -32,   -32,   166,
     -32,   -32,   -32,   -32,   -32,   169,   165,   -32,   -32
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40,    41,     0,     0,    34,     0,     2,     3,     6,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     1,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,     0,     0,    22,     0,     0,
      23,     0,     0,    24,     0,     0,     0,    32,     0,     0,
       0,     0,     0,    47,     0,     0,     0,    28,    21,    48,
      49,    50,    51,    52,    53,    54,    55,    46,    42,    43,
      44,    45,     0,     0,     0,     0,    14,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
      57,    58,    25,    17,    18,    19,    13,     0,    10,     0,
      26,    11,     0,    27,    12,     0,    29,    31,    35,     0,
      36,    16,     7,     8,     9,     0,     0,    30,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -32,   -32,   182,   -32,   -32,    28,    86,   -32,   -31,     0,
      -5
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    16,    17,    18,    19,    58,    97,    98,    37,    38,
      21
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    27,    93,    94,    95,    22,    55,    78,    33,    59,
      41,    42,    43,    44,    45,    46,    57,    25,    20,    60,
      65,    66,    23,    62,    47,    48,    49,    50,    51,    52,
      53,    96,    73,    63,    52,    53,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    24,
      92,    61,    64,   107,   100,    26,    28,   102,     9,    10,
      11,    12,   108,    29,    55,   109,   110,   111,   119,    56,
     122,    13,   125,    39,    57,    34,    35,    36,     4,    68,
       5,     6,    49,    50,    51,    52,    53,    69,     7,     8,
       9,    10,    11,    12,    70,    71,    34,    35,    36,     4,
      72,     5,     6,    13,   126,   127,    14,   118,    15,     7,
       8,     9,    10,    11,    12,    59,    62,    93,    94,    95,
      56,    56,    74,    75,    13,    60,    63,    14,   121,    15,
      76,    34,    35,    36,     4,   137,     5,     6,    50,    51,
      52,    53,    77,    99,     7,     8,     9,    10,    11,    12,
     101,   103,     1,     2,     3,     4,   106,     5,     6,    13,
     113,   114,    14,   124,    15,     7,     8,     9,    10,    11,
      12,   115,   116,    34,    35,    36,     4,   117,     5,     6,
      13,   128,   129,    14,   130,    15,     7,     8,     9,    10,
      11,    12,    30,    31,    32,   132,   133,   134,   135,   136,
      40,    13,   138,   131,    14,     0,    15,     9,    10,    11,
      12,    41,    42,    43,    44,    45,    46,     0,     0,     0,
      13,     0,     0,     0,     0,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,    54,    41,    42,
      43,    44,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,    67,    41,    42,    43,    44,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
       0,   112,    41,    42,    43,    44,    45,    46,     0,     0,
       0,     0,     0,     0,     0,     0,    47,    48,    49,    50,
      51,    52,    53,     0,     0,     0,     0,     0,   120,    41,
      42,    43,    44,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,   123,    41,    42,    43,    44,
      45,    46,     0,     0,     0,     0,     0,     0,     0,     0,
      47,    48,    49,    50,    51,    52,    53,     0,   104,    41,
      42,    43,    44,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,    47,    48,    49,    50,    51,    52,    53,
       0,   105
};

static const yytype_int16 yycheck[] =
{
       0,     6,     4,     5,     6,    19,    27,    38,    13,    27,
      11,    12,    13,    14,    15,    16,    37,    32,    18,    37,
      25,    26,    19,    27,    25,    26,    27,    28,    29,    30,
      31,    33,    33,    37,    30,    31,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    19,
      55,    23,    24,    24,    59,    32,    32,    62,    19,    20,
      21,    22,    33,    32,    27,    70,    71,    72,    99,    32,
     101,    32,   103,     0,    37,     4,     5,     6,     7,    19,
       9,    10,    27,    28,    29,    30,    31,    23,    17,    18,
      19,    20,    21,    22,    33,    33,     4,     5,     6,     7,
      33,     9,    10,    32,   104,   105,    35,    36,    37,    17,
      18,    19,    20,    21,    22,    27,    27,     4,     5,     6,
      32,    32,    19,    19,    32,    37,    37,    35,    36,    37,
      19,     4,     5,     6,     7,   135,     9,    10,    28,    29,
      30,    31,    36,    35,    17,    18,    19,    20,    21,    22,
      35,    35,     4,     5,     6,     7,    33,     9,    10,    32,
      19,    19,    35,    36,    37,    17,    18,    19,    20,    21,
      22,    19,    33,     4,     5,     6,     7,    24,     9,    10,
      32,    37,    19,    35,    37,    37,    17,    18,    19,    20,
      21,    22,     4,     5,     6,    36,    36,    36,     8,    33,
      18,    32,    37,   117,    35,    -1,    37,    19,    20,    21,
      22,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    37,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    37,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    37,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    37,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      -1,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,     7,     9,    10,    17,    18,    19,
      20,    21,    22,    32,    35,    37,    39,    40,    41,    42,
      47,    48,    19,    19,    19,    32,    32,    48,    32,    32,
       4,     5,     6,    48,     4,     5,     6,    46,    47,     0,
      40,    11,    12,    13,    14,    15,    16,    25,    26,    27,
      28,    29,    30,    31,    37,    27,    32,    37,    43,    27,
      37,    43,    27,    37,    43,    48,    48,    37,    19,    23,
      33,    33,    33,    33,    19,    19,    19,    36,    46,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,     4,     5,     6,    33,    44,    45,    35,
      48,    35,    48,    35,    33,    33,    33,    24,    33,    48,
      48,    48,    37,    19,    19,    19,    33,    24,    36,    46,
      37,    36,    46,    37,    36,    46,    47,    47,    37,    19,
      37,    44,    36,    36,    36,     8,    33,    47,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    42,
      42,    42,    42,    43,    43,    44,    44,    45,    45,    45,
      46,    46,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     6,     6,     6,
       5,     5,     5,     3,     2,     1,     3,     2,     2,     2,
       1,     2,     3,     3,     3,     5,     5,     5,     3,     5,
       7,     5,     3,     2,     1,     5,     5,     7,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* unit: statement  */
#line 70 "compiler.y"
                                                                { eval((yyvsp[0].nodPtr));}
#line 1370 "compiler.tab.c"
    break;

  case 6: /* unit: function  */
#line 71 "compiler.y"
                                                                { eval((yyvsp[0].nodPtr));}
#line 1376 "compiler.tab.c"
    break;

  case 7: /* function: INT IDENTIF paramadecl '{' statements '}'  */
#line 73 "compiler.y"
                                                                { (yyval.nodPtr) = (yyvsp[-1].nodPtr);}
#line 1382 "compiler.tab.c"
    break;

  case 8: /* function: FLOAT IDENTIF paramadecl '{' statements '}'  */
#line 74 "compiler.y"
                                                                { (yyval.nodPtr) = (yyvsp[-1].nodPtr);}
#line 1388 "compiler.tab.c"
    break;

  case 9: /* function: DOUBLE IDENTIF paramadecl '{' statements '}'  */
#line 75 "compiler.y"
                                                                { (yyval.nodPtr) = (yyvsp[-1].nodPtr);}
#line 1394 "compiler.tab.c"
    break;

  case 10: /* function: INT IDENTIF paramadecl '{' '}'  */
#line 76 "compiler.y"
                                                                {}
#line 1400 "compiler.tab.c"
    break;

  case 11: /* function: FLOAT IDENTIF paramadecl '{' '}'  */
#line 77 "compiler.y"
                                                                {}
#line 1406 "compiler.tab.c"
    break;

  case 12: /* function: DOUBLE IDENTIF paramadecl '{' '}'  */
#line 78 "compiler.y"
                                                                {}
#line 1412 "compiler.tab.c"
    break;

  case 20: /* statements: statement  */
#line 90 "compiler.y"
                                                                    { (yyval.nodPtr) = (yyvsp[0].nodPtr);}
#line 1418 "compiler.tab.c"
    break;

  case 21: /* statements: statement statements  */
#line 91 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(';', 2, (yyvsp[-1].nodPtr), (yyvsp[0].nodPtr));}
#line 1424 "compiler.tab.c"
    break;

  case 22: /* statement: INT IDENTIF ';'  */
#line 93 "compiler.y"
                                                                    { 
                                                                        symbolTable[*(yyvsp[-1].key)].type = (ValType)1; 
                                                                        symbolTable[*(yyvsp[-1].key)].intValue = 0;
                                                                        (yyval.nodPtr) = nodOper('=', 2, nodId(*(yyvsp[-1].key)), nodConst((ValType)1, 0, 0.0, 0.0));
                                                                    }
#line 1434 "compiler.tab.c"
    break;

  case 23: /* statement: FLOAT IDENTIF ';'  */
#line 98 "compiler.y"
                                                                    { 
                                                                        symbolTable[*(yyvsp[-1].key)].type = (ValType)2; 
                                                                        symbolTable[*(yyvsp[-1].key)].floatValue = 0.0;
                                                                        (yyval.nodPtr) = nodOper('=', 2, nodId(*(yyvsp[-1].key)), nodConst((ValType)2, 0, 0.0, 0.0));
                                                                    }
#line 1444 "compiler.tab.c"
    break;

  case 24: /* statement: DOUBLE IDENTIF ';'  */
#line 103 "compiler.y"
                                                                    { 
                                                                        symbolTable[*(yyvsp[-1].key)].type = (ValType)3; 
                                                                        symbolTable[*(yyvsp[-1].key)].doubleValue = 0.0;
                                                                        (yyval.nodPtr) = nodOper('=', 2, nodId(*(yyvsp[-1].key)), nodConst((ValType)3, 0, 0.0, 0.0));
                                                                    }
#line 1454 "compiler.tab.c"
    break;

  case 25: /* statement: INT IDENTIF '=' expression ';'  */
#line 108 "compiler.y"
                                                                    { 
                                                                        symbolTable[*(yyvsp[-3].key)].type = (ValType)1; 
                                                                        symbolTable[*(yyvsp[-3].key)].intValue = 0;
                                                                        (yyval.nodPtr) = nodOper('=', 2, nodId(*(yyvsp[-3].key)), (yyvsp[-1].nodPtr));
                                                                    }
#line 1464 "compiler.tab.c"
    break;

  case 26: /* statement: FLOAT IDENTIF '=' expression ';'  */
#line 113 "compiler.y"
                                                                    { 
                                                                        symbolTable[*(yyvsp[-3].key)].type = (ValType)2; 
                                                                        symbolTable[*(yyvsp[-3].key)].floatValue = 0.0;
                                                                        (yyval.nodPtr) = nodOper('=', 2, nodId(*(yyvsp[-3].key)), (yyvsp[-1].nodPtr));
                                                                    }
#line 1474 "compiler.tab.c"
    break;

  case 27: /* statement: DOUBLE IDENTIF '=' expression ';'  */
#line 118 "compiler.y"
                                                                    { 
                                                                        symbolTable[*(yyvsp[-3].key)].type = (ValType)3; 
                                                                        symbolTable[*(yyvsp[-3].key)].doubleValue = 0.0;
                                                                        (yyval.nodPtr) = nodOper('=', 2, nodId(*(yyvsp[-3].key)), (yyvsp[-1].nodPtr));
                                                                    }
#line 1484 "compiler.tab.c"
    break;

  case 28: /* statement: '{' statements '}'  */
#line 123 "compiler.y"
                                                                    { (yyval.nodPtr) = (yyvsp[-1].nodPtr);}
#line 1490 "compiler.tab.c"
    break;

  case 29: /* statement: IF '(' expression ')' statement  */
#line 124 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(IF, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr)); }
#line 1496 "compiler.tab.c"
    break;

  case 30: /* statement: IF '(' expression ')' statement ELSE statement  */
#line 125 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(IF, 3, (yyvsp[-4].nodPtr), (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 1502 "compiler.tab.c"
    break;

  case 31: /* statement: WHILE '(' expression ')' statement  */
#line 126 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(WHILE, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 1508 "compiler.tab.c"
    break;

  case 32: /* statement: RETURN expression ';'  */
#line 127 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(RETURN, 1, (yyvsp[-1].nodPtr));}
#line 1514 "compiler.tab.c"
    break;

  case 33: /* statement: expression ';'  */
#line 128 "compiler.y"
                                                                    { (yyval.nodPtr) = (yyvsp[-1].nodPtr); }
#line 1520 "compiler.tab.c"
    break;

  case 34: /* statement: ';'  */
#line 129 "compiler.y"
                                                                    { (yyval.nodPtr) = nodConst((ValType)1, 0, 0.0, 0.0);}
#line 1526 "compiler.tab.c"
    break;

  case 35: /* statement: SCANF '(' IDENTIF ')' ';'  */
#line 130 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(SCANF, 1, nodId(*(yyvsp[-2].key)));}
#line 1532 "compiler.tab.c"
    break;

  case 36: /* statement: PRINTF '(' STRING ')' ';'  */
#line 131 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(PRINTF, 1, nodConst((yyvsp[-2].stringVal))); }
#line 1538 "compiler.tab.c"
    break;

  case 37: /* statement: PRINTF '(' STRING ',' IDENTIF ')' ';'  */
#line 132 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(PRINTF, 2, nodConst((yyvsp[-4].stringVal)), nodId(*(yyvsp[-2].key))); }
#line 1544 "compiler.tab.c"
    break;

  case 38: /* expression: IDENTIF  */
#line 134 "compiler.y"
                                                                    { (yyval.nodPtr) = nodId(*(yyvsp[0].key)); }
#line 1550 "compiler.tab.c"
    break;

  case 39: /* expression: INT_VALUE  */
#line 135 "compiler.y"
                                                                    { (yyval.nodPtr) = nodConst((ValType)1, (yyvsp[0].intVal), 0.0, 0.0); }
#line 1556 "compiler.tab.c"
    break;

  case 40: /* expression: FLOAT_VALUE  */
#line 136 "compiler.y"
                                                                    { (yyval.nodPtr) = nodConst((ValType)2, 0, (yyvsp[0].floatVal), 0.0); }
#line 1562 "compiler.tab.c"
    break;

  case 41: /* expression: DOUBLE_VALUE  */
#line 137 "compiler.y"
                                                                    { (yyval.nodPtr) = nodConst((ValType)3, 0, 0.0, (yyvsp[0].doubleVal)); }
#line 1568 "compiler.tab.c"
    break;

  case 42: /* expression: expression '+' expression  */
#line 138 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper('+', 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 1574 "compiler.tab.c"
    break;

  case 43: /* expression: expression '-' expression  */
#line 139 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper('-', 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 1580 "compiler.tab.c"
    break;

  case 44: /* expression: expression '*' expression  */
#line 140 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper('*', 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 1586 "compiler.tab.c"
    break;

  case 45: /* expression: expression '/' expression  */
#line 141 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper('/', 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr));}
#line 1592 "compiler.tab.c"
    break;

  case 46: /* expression: expression '=' expression  */
#line 142 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper('=', 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr)); }
#line 1598 "compiler.tab.c"
    break;

  case 47: /* expression: '(' expression ')'  */
#line 143 "compiler.y"
                                                                    { (yyval.nodPtr) = (yyvsp[-1].nodPtr); }
#line 1604 "compiler.tab.c"
    break;

  case 48: /* expression: expression EQ expression  */
#line 144 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(EQ, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr)); }
#line 1610 "compiler.tab.c"
    break;

  case 49: /* expression: expression NE expression  */
#line 145 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(NE, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr)); }
#line 1616 "compiler.tab.c"
    break;

  case 50: /* expression: expression LT expression  */
#line 146 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(LT, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr)); }
#line 1622 "compiler.tab.c"
    break;

  case 51: /* expression: expression LE expression  */
#line 147 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(LE, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr)); }
#line 1628 "compiler.tab.c"
    break;

  case 52: /* expression: expression GT expression  */
#line 148 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(GT, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr)); }
#line 1634 "compiler.tab.c"
    break;

  case 53: /* expression: expression GE expression  */
#line 149 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(GE, 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr)); }
#line 1640 "compiler.tab.c"
    break;

  case 54: /* expression: expression '<' expression  */
#line 150 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper('<', 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr)); }
#line 1646 "compiler.tab.c"
    break;

  case 55: /* expression: expression '>' expression  */
#line 151 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper('>', 2, (yyvsp[-2].nodPtr), (yyvsp[0].nodPtr)); }
#line 1652 "compiler.tab.c"
    break;

  case 56: /* expression: '(' INT ')' expression  */
#line 152 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(INT, 1, (yyvsp[0].nodPtr)); }
#line 1658 "compiler.tab.c"
    break;

  case 57: /* expression: '(' FLOAT ')' expression  */
#line 153 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(FLOAT, 1, (yyvsp[0].nodPtr)); }
#line 1664 "compiler.tab.c"
    break;

  case 58: /* expression: '(' DOUBLE ')' expression  */
#line 154 "compiler.y"
                                                                    { (yyval.nodPtr) = nodOper(DOUBLE, 1, (yyvsp[0].nodPtr)); }
#line 1670 "compiler.tab.c"
    break;


#line 1674 "compiler.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 157 "compiler.y"


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