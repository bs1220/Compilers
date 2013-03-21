/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>
#include "tree.h"
#include "hash.h"



int yylineno;

enum nodeTypes {PROGRAM, DECLLIST, DECL, VARDECL, TYPESPECIFIER, FUNDECL, FORMALDECLLIST, FORMALDECL, FUNBODY, LOCALDECLLIST, STATEMENTLIST, STATEMENT, COMPOUNDSTMT, ASSIGNSTMT, CONDSTMT, LOOPSTMT, RETURNSTMT, VAR, EXPRESSION, RELOP, ADDEXPR, ADDOP, TERM, MULOP, FACTOR, FUNCCALLEXPR, ARGLIST, IDENTIFIER, INTCONSTANT, CHARCONSTANT, STRCONSTANT};

enum operators {ADD, SUB, MUL, DIV, LTE, GTE, EQ, NEQ, ASGN, LT, GT};

enum dataType {INT, CHAR, VOID, STRING};
int scope = 0;
int count = 0;
int saveyylval;


tree *AST;


/* Line 268 of yacc.c  */
#line 94 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     INTCONST = 259,
     CHARCONST = 260,
     STRCONST = 261,
     KWD_IF = 262,
     KWD_ELSE = 263,
     KWD_WHILE = 264,
     KWD_INT = 265,
     KWD_STRING = 266,
     KWD_CHAR = 267,
     KWD_RETURN = 268,
     KWD_VOID = 269,
     OPER_ADD = 270,
     OPER_SUB = 271,
     OPER_MUL = 272,
     OPER_DIV = 273,
     OPER_LT = 274,
     OPER_GT = 275,
     OPER_GTE = 276,
     OPER_LTE = 277,
     OPER_EQ = 278,
     OPER_NEQ = 279,
     OPER_ASGN = 280,
     LSQ_BRKT = 281,
     RSQ_BRKT = 282,
     LCRLY_BRKT = 283,
     RCRLY_BRKT = 284,
     LPAREN = 285,
     RPAREN = 286,
     COMMA = 287,
     SEMICLN = 288,
     ILLEGAL_TOK = 289,
     ERROR = 290,
     XIF = 291
   };
#endif
/* Tokens.  */
#define ID 258
#define INTCONST 259
#define CHARCONST 260
#define STRCONST 261
#define KWD_IF 262
#define KWD_ELSE 263
#define KWD_WHILE 264
#define KWD_INT 265
#define KWD_STRING 266
#define KWD_CHAR 267
#define KWD_RETURN 268
#define KWD_VOID 269
#define OPER_ADD 270
#define OPER_SUB 271
#define OPER_MUL 272
#define OPER_DIV 273
#define OPER_LT 274
#define OPER_GT 275
#define OPER_GTE 276
#define OPER_LTE 277
#define OPER_EQ 278
#define OPER_NEQ 279
#define OPER_ASGN 280
#define LSQ_BRKT 281
#define RSQ_BRKT 282
#define LCRLY_BRKT 283
#define RCRLY_BRKT 284
#define LPAREN 285
#define RPAREN 286
#define COMMA 287
#define SEMICLN 288
#define ILLEGAL_TOK 289
#define ERROR 290
#define XIF 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 24 "parser.y"

   int val;
   char *str;
   struct treenode *node;



/* Line 293 of yacc.c  */
#line 210 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 222 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   140

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  117

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    15,    23,
      27,    29,    31,    33,    35,    36,    44,    45,    52,    54,
      58,    61,    66,    71,    72,    75,    76,    79,    81,    83,
      85,    87,    89,    90,    91,    97,   102,   105,   111,   119,
     125,   128,   132,   134,   135,   141,   143,   147,   149,   151,
     153,   155,   157,   159,   161,   165,   167,   169,   171,   175,
     177,   179,   183,   185,   187,   189,   191,   193,   194,   200,
     204,   206
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    39,    -1,    40,    -1,    39,    40,    -1,
      41,    -1,    44,    -1,    -1,    43,     3,    26,    42,     4,
      27,    33,    -1,    43,     3,    33,    -1,    10,    -1,    12,
      -1,    14,    -1,    11,    -1,    -1,    43,     3,    30,    45,
      47,    31,    49,    -1,    -1,    43,     3,    30,    31,    46,
      49,    -1,    48,    -1,    48,    32,    47,    -1,    43,     3,
      -1,    43,     3,    26,    27,    -1,    28,    50,    51,    29,
      -1,    -1,    41,    50,    -1,    -1,    52,    51,    -1,    53,
      -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,    -1,
      -1,    28,    54,    51,    55,    29,    -1,    60,    25,    62,
      33,    -1,    62,    33,    -1,     7,    30,    62,    31,    52,
      -1,     7,    30,    62,    31,    52,     8,    52,    -1,     9,
      30,    62,    31,    52,    -1,    13,    33,    -1,    13,    62,
      33,    -1,     3,    -1,    -1,     3,    26,    61,    64,    27,
      -1,    64,    -1,    62,    63,    64,    -1,    21,    -1,    20,
      -1,    19,    -1,    22,    -1,    23,    -1,    24,    -1,    66,
      -1,    64,    65,    66,    -1,    15,    -1,    16,    -1,    68,
      -1,    66,    67,    68,    -1,    17,    -1,    18,    -1,    30,
      62,    31,    -1,    60,    -1,    69,    -1,     4,    -1,     5,
      -1,     6,    -1,    -1,     3,    30,    70,    71,    31,    -1,
       3,    30,    31,    -1,    62,    -1,    71,    32,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    82,    88,    97,   103,   111,   111,   120,
     131,   135,   139,   143,   149,   149,   159,   159,   170,   176,
     185,   193,   203,   214,   218,   228,   232,   241,   245,   249,
     253,   257,   263,   263,   263,   271,   278,   287,   294,   304,
     313,   318,   326,   330,   330,   339,   345,   355,   359,   363,
     367,   371,   375,   381,   385,   395,   399,   405,   409,   419,
     423,   429,   433,   437,   441,   445,   449,   454,   454,   461,
     469,   475
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTCONST", "CHARCONST",
  "STRCONST", "KWD_IF", "KWD_ELSE", "KWD_WHILE", "KWD_INT", "KWD_STRING",
  "KWD_CHAR", "KWD_RETURN", "KWD_VOID", "OPER_ADD", "OPER_SUB", "OPER_MUL",
  "OPER_DIV", "OPER_LT", "OPER_GT", "OPER_GTE", "OPER_LTE", "OPER_EQ",
  "OPER_NEQ", "OPER_ASGN", "LSQ_BRKT", "RSQ_BRKT", "LCRLY_BRKT",
  "RCRLY_BRKT", "LPAREN", "RPAREN", "COMMA", "SEMICLN", "ILLEGAL_TOK",
  "ERROR", "XIF", "$accept", "program", "declList", "decl", "varDecl",
  "$@1", "typeSpecifier", "funDecl", "$@2", "$@3", "formalDeclList",
  "formalDecl", "funBody", "localDeclList", "statementList", "statement",
  "compoundStmt", "$@4", "$@5", "assignStmt", "condStmt", "loopStmt",
  "returnStmt", "var", "$@6", "expression", "relop", "addExpr", "addop",
  "term", "mulop", "factor", "funcCallExpr", "$@7", "argList", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    42,    41,    41,
      43,    43,    43,    43,    45,    44,    46,    44,    47,    47,
      48,    48,    49,    50,    50,    51,    51,    52,    52,    52,
      52,    52,    54,    55,    53,    56,    56,    57,    57,    58,
      59,    59,    60,    61,    60,    62,    62,    63,    63,    63,
      63,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    70,    69,    69,
      71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     0,     7,     3,
       1,     1,     1,     1,     0,     7,     0,     6,     1,     3,
       2,     4,     4,     0,     2,     0,     2,     1,     1,     1,
       1,     1,     0,     0,     5,     4,     2,     5,     7,     5,
       2,     3,     1,     0,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    13,    11,    12,     0,     2,     3,     5,     0,
       6,     1,     4,     0,     7,    14,     9,     0,    16,     0,
       0,     0,     0,     0,    18,     0,    23,    17,    20,     0,
       0,     8,    23,     0,    25,     0,    15,    19,    24,     0,
      42,    64,    65,    66,     0,     0,     0,    32,     0,     0,
      25,    27,    28,    29,    30,    31,    62,     0,    45,    53,
      57,    63,    21,    43,    67,     0,     0,    40,    62,     0,
      25,     0,    22,    26,     0,    49,    48,    47,    50,    51,
      52,    36,     0,    55,    56,     0,    59,    60,     0,     0,
      69,     0,     0,     0,    41,    33,    61,     0,    46,    54,
      58,     0,    70,     0,     0,     0,     0,    35,    44,    68,
       0,    37,    39,    34,    71,     0,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    17,     9,    10,    19,    21,
      23,    24,    27,    34,    49,    50,    51,    70,   106,    52,
      53,    54,    55,    68,    89,    57,    82,    58,    85,    59,
      88,    60,    61,    91,   103
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int8 yypact[] =
{
      90,   -78,   -78,   -78,   -78,     2,    90,   -78,   -78,    10,
     -78,   -78,   -78,    34,   -78,   -16,   -78,    41,   -78,    90,
      23,    33,    63,    48,    71,    82,    90,   -78,    91,    33,
      90,   -78,    90,   113,     5,    92,   -78,   -78,   -78,    52,
      54,   -78,   -78,   -78,    97,    98,     1,   -78,    19,   100,
       5,   -78,   -78,   -78,   -78,   -78,   105,    20,    32,    65,
     -78,   -78,   -78,   -78,   101,    19,    19,   -78,   -78,    35,
       5,    68,   -78,   -78,    19,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,    19,   -78,   -78,    19,   -78,   -78,    19,    19,
     -78,    19,    74,    87,   -78,   -78,   -78,    53,    32,    65,
     -78,    36,   102,    81,     5,     5,   104,   -78,   -78,   -78,
      19,   123,   -78,   -78,   102,     5,   -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   -78,   128,    88,   -78,     0,   -78,   -78,   -78,
     106,   -78,   108,   103,   -33,   -77,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -34,   -78,   -45,   -78,   -20,   -78,    55,
     -78,    50,   -78,   -78,   -78
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      56,    69,    11,    71,    40,    41,    42,    43,    40,    41,
      42,    43,    44,    13,    45,    18,    56,    73,    46,    22,
      92,    93,    40,    41,    42,    43,    33,   111,   112,    97,
      22,    48,    33,    47,    67,    48,    56,    95,   116,    75,
      76,    77,    78,    79,    80,    20,   102,    83,    84,    48,
      25,    83,    84,    81,    75,    76,    77,    78,    79,    80,
      14,    26,    98,   108,    15,   114,    28,    16,    94,   101,
      56,    56,    75,    76,    77,    78,    79,    80,    14,    29,
      63,    56,    86,    87,    64,    16,   107,    75,    76,    77,
      78,    79,    80,    75,    76,    77,    78,    79,    80,    96,
       1,     2,     3,    30,     4,   104,    75,    76,    77,    78,
      79,    80,   109,   110,    32,    31,    39,    35,   105,    62,
      32,    75,    76,    77,    78,    79,    80,    65,    66,    72,
      74,   115,    90,   113,    12,    38,    37,    36,   100,     0,
      99
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-78))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      34,    46,     0,    48,     3,     4,     5,     6,     3,     4,
       5,     6,     7,     3,     9,    31,    50,    50,    13,    19,
      65,    66,     3,     4,     5,     6,    26,   104,   105,    74,
      30,    30,    32,    28,    33,    30,    70,    70,   115,    19,
      20,    21,    22,    23,    24,     4,    91,    15,    16,    30,
      27,    15,    16,    33,    19,    20,    21,    22,    23,    24,
      26,    28,    82,    27,    30,   110,     3,    33,    33,    89,
     104,   105,    19,    20,    21,    22,    23,    24,    26,    31,
      26,   115,    17,    18,    30,    33,    33,    19,    20,    21,
      22,    23,    24,    19,    20,    21,    22,    23,    24,    31,
      10,    11,    12,    32,    14,    31,    19,    20,    21,    22,
      23,    24,    31,    32,    26,    33,     3,    26,    31,    27,
      32,    19,    20,    21,    22,    23,    24,    30,    30,    29,
      25,     8,    31,    29,     6,    32,    30,    29,    88,    -1,
      85
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    12,    14,    38,    39,    40,    41,    43,
      44,     0,    40,     3,    26,    30,    33,    42,    31,    45,
       4,    46,    43,    47,    48,    27,    28,    49,     3,    31,
      32,    33,    41,    43,    50,    26,    49,    47,    50,     3,
       3,     4,     5,     6,     7,     9,    13,    28,    30,    51,
      52,    53,    56,    57,    58,    59,    60,    62,    64,    66,
      68,    69,    27,    26,    30,    30,    30,    33,    60,    62,
      54,    62,    29,    51,    25,    19,    20,    21,    22,    23,
      24,    33,    63,    15,    16,    65,    17,    18,    67,    61,
      31,    70,    62,    62,    33,    51,    31,    62,    64,    66,
      68,    64,    62,    71,    31,    31,    55,    33,    27,    31,
      32,    52,    52,    29,    62,     8,    52
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 75 "parser.y"
    {
                        tree *progNode = maketree(PROGRAM);
                        addChild(progNode, (yyvsp[(1) - (1)].node));
                        AST = progNode;
                     }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 83 "parser.y"
    {
                        tree *declListNode = maketree(DECLLIST);
                        addChild(declListNode, (yyvsp[(1) - (1)].node));
                        (yyval.node) = declListNode;
                     }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 89 "parser.y"
    {
                        tree *declListNode = maketree(DECLLIST);
                        addChild(declListNode, (yyvsp[(1) - (2)].node));
                        addChild(declListNode, (yyvsp[(2) - (2)].node));
                        (yyval.node) = declListNode;
                     }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 98 "parser.y"
    {
                        tree *declNode = maketree(DECL);
                        addChild(declNode, (yyvsp[(1) - (1)].node));
                        (yyval.node) = declNode;
                     }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 104 "parser.y"
    {
                        tree *declNode = maketree(DECL);
                        addChild(declNode, (yyvsp[(1) - (1)].node));
                        (yyval.node) = declNode;
                     }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 111 "parser.y"
    {saveyylval = yylval.val;}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 112 "parser.y"
    {
                        stupdate(saveyylval, (yyvsp[(1) - (7)].node)->val, scope);
                        tree *declNode = maketree(VARDECL);
                        addChild(declNode, (yyvsp[(1) - (7)].node));
                        addChild(declNode, maketreeWithVal(IDENTIFIER,saveyylval));
                        addChild(declNode, maketreeWithVal(INTCONSTANT,yylval.val));
                        (yyval.node) = declNode;
                     }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 121 "parser.y"
    {
                        stupdate(yylval.val, (yyvsp[(1) - (3)].node)->val, scope);
						tree *declNode = maketree(VARDECL);
                        addChild(declNode, (yyvsp[(1) - (3)].node));
						stupdate(yylval.val, (yyvsp[(1) - (3)].node)->val, scope);
                        addChild(declNode, maketreeWithVal(IDENTIFIER,yylval.val));
                        (yyval.node) = declNode;
                     }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 132 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(TYPESPECIFIER, INT);
                     }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 136 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(TYPESPECIFIER, CHAR);
                     }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 140 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(TYPESPECIFIER, VOID);
                     }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 144 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(TYPESPECIFIER, STRING);
                     }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 149 "parser.y"
    {saveyylval = yylval.val; scope++;}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 150 "parser.y"
    {
						stupdate(saveyylval, (yyvsp[(1) - (7)].node)->val, scope);
                        tree *functionNode = maketree(FUNDECL);
                        addChild(functionNode, (yyvsp[(1) - (7)].node));
                        addChild(functionNode, maketreeWithVal(IDENTIFIER,saveyylval));
                        addChild(functionNode, (yyvsp[(5) - (7)].node));
                        addChild(functionNode, (yyvsp[(7) - (7)].node));
                        (yyval.node) = functionNode;
                     }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 159 "parser.y"
    { saveyylval = yylval.val;}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 160 "parser.y"
    {
                        stupdate(saveyylval, (yyvsp[(1) - (6)].node)->val, scope);
						tree *functionNode = maketree(FUNDECL);
                        addChild(functionNode, (yyvsp[(1) - (6)].node));
                        addChild(functionNode, maketreeWithVal(IDENTIFIER,saveyylval));
                        addChild(functionNode, (yyvsp[(6) - (6)].node));
                        (yyval.node) = functionNode;
                     }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 171 "parser.y"
    {
                        tree *formalDeclListNode = maketree(FORMALDECLLIST);
                        addChild(formalDeclListNode, (yyvsp[(1) - (1)].node));
                        (yyval.node) = formalDeclListNode;
                     }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 177 "parser.y"
    {
                        tree *formalDeclListNode = maketree(FORMALDECLLIST);
                        addChild(formalDeclListNode, (yyvsp[(1) - (3)].node));
                        addChild(formalDeclListNode, (yyvsp[(3) - (3)].node));
                        (yyval.node) = formalDeclListNode;
                     }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 186 "parser.y"
    {
						stupdate(yylval.val, (yyvsp[(1) - (2)].node)->val, scope);
                        tree *declNode = maketree(FORMALDECL);
                        addChild(declNode, (yyvsp[(1) - (2)].node));
                        addChild(declNode, maketreeWithVal(IDENTIFIER,yylval.val));
                        (yyval.node) = declNode;
                     }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 194 "parser.y"
    {
                        stupdate(yylval.val, (yyvsp[(1) - (4)].node)->val, scope);
						tree *declNode = maketree(FORMALDECL);
                        addChild(declNode, (yyvsp[(1) - (4)].node));
                        addChild(declNode, maketreeWithVal(IDENTIFIER,yylval.val));
                        (yyval.node) = declNode;
                     }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 204 "parser.y"
    {
                        tree *funBodyNode = maketree(FUNBODY);
                        addChild(funBodyNode, (yyvsp[(2) - (4)].node));
                        addChild(funBodyNode, (yyvsp[(3) - (4)].node));
                        scope--;
						(yyval.node) = funBodyNode;
                     }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 214 "parser.y"
    {
                        tree *localDeclListNode = maketree(LOCALDECLLIST);
                        (yyval.node) = localDeclListNode;
                     }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 219 "parser.y"
    {
                        tree *localDeclListNode = maketree(LOCALDECLLIST);
                        addChild(localDeclListNode, (yyvsp[(1) - (2)].node));
                        addChild(localDeclListNode, (yyvsp[(2) - (2)].node));
                        (yyval.node) = localDeclListNode;
                     }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 228 "parser.y"
    {
                        tree *statementNode = maketree(STATEMENTLIST);
                        (yyval.node) = statementNode;
                     }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 233 "parser.y"
    {
                        tree *statementNode = maketree(STATEMENTLIST);
                        addChild(statementNode, (yyvsp[(1) - (2)].node));
                        addChild(statementNode, (yyvsp[(2) - (2)].node));
                        (yyval.node) = statementNode;
                     }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 242 "parser.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                     }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 246 "parser.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                     }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 250 "parser.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                     }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 254 "parser.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                     }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 258 "parser.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                     }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 263 "parser.y"
    {scope++;}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 263 "parser.y"
    {scope--;}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 264 "parser.y"
    {
                        tree *compoundStmtNode = maketree(COMPOUNDSTMT);
                        addChild(compoundStmtNode, (yyvsp[(3) - (5)].node));
                        (yyval.node) = compoundStmtNode;
                     }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 272 "parser.y"
    {
                        tree *assignmentNode = maketree(ASSIGNSTMT);
                        addChild(assignmentNode, (yyvsp[(1) - (4)].node));
                        addChild(assignmentNode, (yyvsp[(3) - (4)].node));
                        (yyval.node) = assignmentNode;
                     }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 279 "parser.y"
    {
                        tree *assignmentNode = maketree(ASSIGNSTMT);
                        addChild(assignmentNode, (yyvsp[(1) - (2)].node));
                        (yyval.node) = assignmentNode;
                     }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 288 "parser.y"
    {
                        tree *condNode = maketree(CONDSTMT);
                        addChild(condNode, (yyvsp[(3) - (5)].node));
                        addChild(condNode, (yyvsp[(5) - (5)].node));
                        (yyval.node) = condNode;
                     }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 295 "parser.y"
    {
                        tree *condNode = maketree(CONDSTMT);
                        addChild(condNode, (yyvsp[(3) - (7)].node));
                        addChild(condNode, (yyvsp[(5) - (7)].node));
                        addChild(condNode, (yyvsp[(7) - (7)].node));
                        (yyval.node) = condNode;
                     }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 305 "parser.y"
    {
                        tree *loopNode = maketree(LOOPSTMT);
                        addChild(loopNode, (yyvsp[(3) - (5)].node));
                        addChild(loopNode, (yyvsp[(5) - (5)].node));
                        (yyval.node) = loopNode;
                     }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 314 "parser.y"
    {
                        tree *returnStmtNode = maketree(RETURNSTMT);
                        (yyval.node) = returnStmtNode;
                     }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 319 "parser.y"
    {
                        tree *returnNode = maketree(RETURNSTMT);
                        addChild(returnNode, (yyvsp[(2) - (3)].node));
                        (yyval.node) = returnNode;
                     }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 327 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(IDENTIFIER,yylval.val);
                     }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 330 "parser.y"
    {saveyylval = yylval.val; }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 331 "parser.y"
    {
                        tree *varNode = maketree(VAR);
                        addChild(varNode, maketreeWithVal(IDENTIFIER,saveyylval));
                        addChild(varNode, (yyvsp[(4) - (5)].node));
                        (yyval.node) = varNode;
                     }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 340 "parser.y"
    {
                        tree *expNode = maketree(EXPRESSION);
                        addChild(expNode, (yyvsp[(1) - (1)].node));
                        (yyval.node) = expNode;
                     }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 346 "parser.y"
    {
                        tree *expNode = maketree(EXPRESSION);
                        addChild(expNode, (yyvsp[(1) - (3)].node));
                        addChild(expNode, (yyvsp[(2) - (3)].node));
                        addChild(expNode, (yyvsp[(3) - (3)].node));
                        (yyval.node) = expNode;
                     }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 356 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(RELOP,GTE);
                     }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 360 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(RELOP,GT);
                     }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 364 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(RELOP,LT);
                     }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 368 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(RELOP,LTE);
                     }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 372 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(RELOP,EQ);
                     }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 376 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(RELOP,NEQ);
                     }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 382 "parser.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                     }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 386 "parser.y"
    {
                        tree *aeNode = maketree(ADDEXPR);
                        addChild(aeNode, (yyvsp[(1) - (3)].node));
                        addChild(aeNode, (yyvsp[(2) - (3)].node));
                        addChild(aeNode, (yyvsp[(3) - (3)].node));
                        (yyval.node) = aeNode;
                     }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 396 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(ADDOP,ADD);
                     }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 400 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(ADDOP,SUB);
                     }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 406 "parser.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                     }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 410 "parser.y"
    {
                        tree *termNode = maketree(TERM);
                        addChild(termNode, (yyvsp[(1) - (3)].node));
                        addChild(termNode, (yyvsp[(2) - (3)].node));
                        addChild(termNode, (yyvsp[(3) - (3)].node));
                        (yyval.node) = termNode;
                     }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 420 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(MULOP,MUL);
                     }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 424 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(MULOP,DIV);
                     }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 430 "parser.y"
    {
                        (yyval.node) = (yyvsp[(2) - (3)].node);
                     }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 434 "parser.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                     }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 438 "parser.y"
    {
                        (yyval.node) = (yyvsp[(1) - (1)].node);
                     }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 442 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(INTCONSTANT, yylval.val);
                     }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 446 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(CHARCONSTANT, yylval.val);
                     }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 450 "parser.y"
    {
                        (yyval.node) = maketreeWithVal(STRCONSTANT, yylval.val);
                     }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 454 "parser.y"
    {saveyylval = yylval.val;}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 455 "parser.y"
    {
                        tree *funcCall = maketree(FUNCCALLEXPR);
                        addChild(funcCall, maketreeWithVal(IDENTIFIER, saveyylval));
                        addChild(funcCall, (yyvsp[(4) - (5)].node));
                        (yyval.node) = funcCall;
                     }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 462 "parser.y"
    {
                        tree *funcCall = maketree(FUNCCALLEXPR);
                        addChild(funcCall, maketreeWithVal(IDENTIFIER, yylval.val));
                        (yyval.node) = funcCall;
                     }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 470 "parser.y"
    {
                        tree *argList = maketree(ARGLIST);
                        addChild(argList, (yyvsp[(1) - (1)].node));
                        (yyval.node) = argList;
                     }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 476 "parser.y"
    {
                        tree *argList = maketree(ARGLIST);
                        addChild(argList, (yyvsp[(1) - (3)].node));
                        addChild(argList, (yyvsp[(3) - (3)].node));
                        (yyval.node) = argList;
                     }
    break;



/* Line 1806 of yacc.c  */
#line 2283 "y.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
		      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 484 "parser.y"




int main() {
  if (!yyparse()){
    printAst(AST, 1);
  }
  return 0;
}

