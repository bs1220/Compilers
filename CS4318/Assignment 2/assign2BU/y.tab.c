#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
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
#line 23 "parser.y"
typedef union
{
   int val;
   char *str;
   struct treenode *node;
} YYSTYPE;
#line 51 "y.tab.c"
#define ID 257
#define INTCONST 258
#define CHARCONST 259
#define STRCONST 260
#define KWD_IF 261
#define KWD_ELSE 262
#define KWD_WHILE 263
#define KWD_INT 264
#define KWD_STRING 265
#define KWD_CHAR 266
#define KWD_RETURN 267
#define KWD_VOID 268
#define OPER_ADD 269
#define OPER_SUB 270
#define OPER_MUL 271
#define OPER_DIV 272
#define OPER_LT 273
#define OPER_GT 274
#define OPER_GTE 275
#define OPER_LTE 276
#define OPER_EQ 277
#define OPER_NEQ 278
#define OPER_ASGN 279
#define LSQ_BRKT 280
#define RSQ_BRKT 281
#define LCRLY_BRKT 282
#define RCRLY_BRKT 283
#define LPAREN 284
#define RPAREN 285
#define COMMA 286
#define SEMICLN 287
#define ILLEGAL_TOK 288
#define ERROR 289
#define XIF 290
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    1,    2,    2,   27,    3,    3,    4,    4,
    4,    4,   28,    5,   29,    5,    6,    6,    7,    7,
    8,    9,    9,   10,   10,   11,   11,   11,   11,   11,
   30,   31,   12,   13,   13,   14,   14,   15,   16,   16,
   17,   32,   17,   18,   18,   19,   19,   19,   19,   19,
   19,   20,   20,   21,   21,   22,   22,   23,   23,   24,
   24,   24,   24,   24,   24,   25,   25,   26,   26,
};
short yylen[] = {                                         2,
    1,    1,    2,    1,    1,    0,    7,    3,    1,    1,
    1,    1,    0,    7,    0,    6,    1,    3,    2,    4,
    4,    0,    2,    0,    2,    1,    1,    1,    1,    1,
    0,    0,    5,    4,    2,    5,    7,    5,    2,    3,
    1,    0,    5,    1,    3,    1,    1,    1,    1,    1,
    1,    1,    3,    1,    1,    1,    3,    1,    1,    3,
    1,    1,    1,    1,    1,    4,    3,    1,    3,
};
short yydefred[] = {                                      0,
    9,   12,   10,   11,    0,    0,    2,    4,    0,    5,
    3,    0,    6,    0,    8,    0,   15,    0,    0,    0,
    0,    0,    0,    0,    0,   16,    0,    0,    0,    7,
    0,    0,    0,    0,   14,   18,   23,    0,    0,   63,
   64,   65,    0,    0,    0,   31,    0,    0,    0,   26,
   27,   28,   29,   30,    0,    0,    0,    0,   56,   62,
   20,   42,    0,    0,    0,   39,   61,    0,    0,    0,
   21,   25,    0,   48,   47,   46,   49,   50,   51,   35,
    0,   54,   55,    0,   58,   59,    0,    0,   67,    0,
    0,    0,    0,   40,   32,   60,    0,    0,    0,   57,
    0,   66,    0,    0,    0,    0,   34,   43,    0,    0,
   38,   33,    0,   37,
};
short yydgoto[] = {                                       5,
    6,    7,    8,    9,   10,   22,   23,   26,   33,   48,
   49,   50,   51,   52,   53,   54,   67,   56,   81,   57,
   84,   58,   87,   59,   60,   91,   16,   18,   20,   69,
  106,   88,
};
short yysindex[] = {                                    -81,
    0,    0,    0,    0,    0,  -81,    0,    0, -255,    0,
    0, -224,    0, -246,    0, -228,    0,  -81, -236, -218,
 -199, -211, -207, -219,  -81,    0, -160, -218,  -81,    0,
  -81, -161, -206, -177,    0,    0,    0, -210, -266,    0,
    0,    0, -158, -125, -253,    0, -176, -144, -206,    0,
    0,    0,    0,    0, -119,  -99, -171, -153,    0,    0,
    0,    0, -247, -176, -176,    0,    0,  -84, -206,  -63,
    0,    0, -176,    0,    0,    0,    0,    0,    0,    0,
 -176,    0,    0, -176,    0,    0, -176, -176,    0,  -37,
 -151,  -57,  -43,    0,    0,    0,  -78, -171, -153,    0,
 -154,    0, -176, -206, -206,  -97,    0,    0,  -37,  -98,
    0,    0, -206,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,  201,    0,    0,    0,    0,
    0,    0,    0,  -60,    0,    0,    0,    0,    0,    0,
    0,    0, -246,    0, -235,    0, -148,    0,    0,    0,
 -235,    0,  -76,    0,    0,    0,    0,    0, -184,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -76,    0,
    0,    0,    0,    0, -126,    0, -120, -164,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -76,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -123,
    0,    0,    0,    0,    0,    0,    0, -105, -145,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -62, -217,
    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,  196,    2,   44,    0,  197,    0,  199,  194,  -34,
  -96,    0,    0,    0,    0,    0,  -33,  -44,    0,   19,
    0,  145,    0,  156,    0,    0,    0,    0,    0,    0,
    0,    0,
};
#define YYTABLESIZE 243
short yytable[] = {                                      55,
   68,   12,   70,   39,   40,   41,   42,  110,  111,   39,
   40,   41,   42,   62,   72,   55,  114,   63,   90,   92,
   93,   22,   22,   22,   22,   22,   31,   22,   97,   19,
   47,   22,   31,   66,   95,   55,   47,   89,   17,   36,
   36,   36,   36,   36,   24,   36,   22,   22,   22,   36,
   39,   40,   41,   42,   43,   13,   44,   27,  109,   14,
   45,   21,   15,   25,   36,   36,   36,   30,   32,   13,
   55,   55,   21,   28,   32,   46,   15,   47,   29,   55,
   39,   40,   41,   42,   41,   41,   41,   41,   41,   41,
   41,   41,   41,   41,   41,   38,   41,   82,   83,   98,
   41,   41,   41,   61,   52,   52,  101,   47,   52,   52,
   52,   52,   52,   52,   82,   83,   52,   85,   86,   34,
   52,   52,   52,   53,   53,   64,  108,   53,   53,   53,
   53,   53,   53,  102,  103,   53,   19,   19,   71,   53,
   53,   53,   61,   61,   61,   61,   61,   61,   61,   61,
   61,   61,   44,   44,   44,   44,   44,   44,   65,   73,
   61,   68,   68,  113,   44,   44,   44,   45,   45,   45,
   45,   45,   45,   74,   75,   76,   77,   78,   79,   45,
   45,   45,    1,    2,    3,  112,    4,   80,   74,   75,
   76,   77,   78,   79,   74,   75,   76,   77,   78,   79,
    1,   11,   94,   13,   13,   13,   24,   13,  107,   74,
   75,   76,   77,   78,   79,   74,   75,   76,   77,   78,
   79,   96,   69,   69,   37,   36,   35,  104,   99,   74,
   75,   76,   77,   78,   79,   74,   75,   76,   77,   78,
   79,  105,  100,
};
short yycheck[] = {                                      33,
   45,  257,   47,  257,  258,  259,  260,  104,  105,  257,
  258,  259,  260,  280,   49,   49,  113,  284,   63,   64,
   65,  257,  258,  259,  260,  261,   25,  263,   73,  258,
  284,  267,   31,  287,   69,   69,  284,  285,  285,  257,
  258,  259,  260,  261,  281,  263,  282,  283,  284,  267,
  257,  258,  259,  260,  261,  280,  263,  257,  103,  284,
  267,   18,  287,  282,  282,  283,  284,  287,   25,  280,
  104,  105,   29,  285,   31,  282,  287,  284,  286,  113,
  257,  258,  259,  260,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  257,  281,  269,  270,   81,
  285,  286,  287,  281,  269,  270,   88,  284,  273,  274,
  275,  276,  277,  278,  269,  270,  281,  271,  272,  280,
  285,  286,  287,  269,  270,  284,  281,  273,  274,  275,
  276,  277,  278,  285,  286,  281,  285,  286,  283,  285,
  286,  287,  269,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  273,  274,  275,  276,  277,  278,  284,  279,
  287,  285,  286,  262,  285,  286,  287,  273,  274,  275,
  276,  277,  278,  273,  274,  275,  276,  277,  278,  285,
  286,  287,  264,  265,  266,  283,  268,  287,  273,  274,
  275,  276,  277,  278,  273,  274,  275,  276,  277,  278,
    0,    6,  287,  264,  265,  266,  283,  268,  287,  273,
  274,  275,  276,  277,  278,  273,  274,  275,  276,  277,
  278,  285,  285,  286,   31,   29,   28,  285,   84,  273,
  274,  275,  276,  277,  278,  273,  274,  275,  276,  277,
  278,  285,   87,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID","INTCONST","CHARCONST",
"STRCONST","KWD_IF","KWD_ELSE","KWD_WHILE","KWD_INT","KWD_STRING","KWD_CHAR",
"KWD_RETURN","KWD_VOID","OPER_ADD","OPER_SUB","OPER_MUL","OPER_DIV","OPER_LT",
"OPER_GT","OPER_GTE","OPER_LTE","OPER_EQ","OPER_NEQ","OPER_ASGN","LSQ_BRKT",
"RSQ_BRKT","LCRLY_BRKT","RCRLY_BRKT","LPAREN","RPAREN","COMMA","SEMICLN",
"ILLEGAL_TOK","ERROR","XIF",
};
char *yyrule[] = {
"$accept : program",
"program : declList",
"declList : decl",
"declList : declList decl",
"decl : varDecl",
"decl : funDecl",
"$$1 :",
"varDecl : typeSpecifier ID LSQ_BRKT $$1 INTCONST RSQ_BRKT SEMICLN",
"varDecl : typeSpecifier ID SEMICLN",
"typeSpecifier : KWD_INT",
"typeSpecifier : KWD_CHAR",
"typeSpecifier : KWD_VOID",
"typeSpecifier : KWD_STRING",
"$$2 :",
"funDecl : typeSpecifier ID LPAREN $$2 formalDeclList RPAREN funBody",
"$$3 :",
"funDecl : typeSpecifier ID LPAREN RPAREN $$3 funBody",
"formalDeclList : formalDecl",
"formalDeclList : formalDecl COMMA formalDeclList",
"formalDecl : typeSpecifier ID",
"formalDecl : typeSpecifier ID LSQ_BRKT RSQ_BRKT",
"funBody : LCRLY_BRKT localDeclList statementList RCRLY_BRKT",
"localDeclList :",
"localDeclList : varDecl localDeclList",
"statementList :",
"statementList : statement statementList",
"statement : compoundStmt",
"statement : assignStmt",
"statement : condStmt",
"statement : loopStmt",
"statement : returnStmt",
"$$4 :",
"$$5 :",
"compoundStmt : LCRLY_BRKT $$4 statementList $$5 RCRLY_BRKT",
"assignStmt : var OPER_ASGN expression SEMICLN",
"assignStmt : expression SEMICLN",
"condStmt : KWD_IF LPAREN expression RPAREN statement",
"condStmt : KWD_IF LPAREN expression RPAREN statement KWD_ELSE statement",
"loopStmt : KWD_WHILE LPAREN expression RPAREN statement",
"returnStmt : KWD_RETURN SEMICLN",
"returnStmt : KWD_RETURN expression SEMICLN",
"var : ID",
"$$6 :",
"var : ID LSQ_BRKT $$6 addExpr RSQ_BRKT",
"expression : addExpr",
"expression : expression relop addExpr",
"relop : OPER_GTE",
"relop : OPER_GT",
"relop : OPER_LT",
"relop : OPER_LTE",
"relop : OPER_EQ",
"relop : OPER_NEQ",
"addExpr : term",
"addExpr : addExpr addop term",
"addop : OPER_ADD",
"addop : OPER_SUB",
"term : factor",
"term : term mulop factor",
"mulop : OPER_MUL",
"mulop : OPER_DIV",
"factor : LPAREN expression RPAREN",
"factor : var",
"factor : funcCallExpr",
"factor : INTCONST",
"factor : CHARCONST",
"factor : STRCONST",
"funcCallExpr : ID LPAREN argList RPAREN",
"funcCallExpr : ID LPAREN RPAREN",
"argList : expression",
"argList : argList COMMA expression",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 484 "parser.y"




int main() {
  if (!yyparse()){
    printAst(AST, 1);
  }
  return 0;
}
#line 351 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 75 "parser.y"
{
                        tree *progNode = maketree(PROGRAM);
                        addChild(progNode, yyvsp[0].node);
                        AST = progNode;
                     }
break;
case 2:
#line 83 "parser.y"
{
                        tree *declListNode = maketree(DECLLIST);
                        addChild(declListNode, yyvsp[0].node);
                        yyval.node = declListNode;
                     }
break;
case 3:
#line 89 "parser.y"
{
                        tree *declListNode = maketree(DECLLIST);
                        addChild(declListNode, yyvsp[-1].node);
                        addChild(declListNode, yyvsp[0].node);
                        yyval.node = declListNode;
                     }
break;
case 4:
#line 98 "parser.y"
{
                        tree *declNode = maketree(DECL);
                        addChild(declNode, yyvsp[0].node);
                        yyval.node = declNode;
                     }
break;
case 5:
#line 104 "parser.y"
{
                        tree *declNode = maketree(DECL);
                        addChild(declNode, yyvsp[0].node);
                        yyval.node = declNode;
                     }
break;
case 6:
#line 111 "parser.y"
{saveyylval = yylval.val;}
break;
case 7:
#line 112 "parser.y"
{
                        stupdate(saveyylval, yyvsp[-6].node->val, scope);
                        tree *declNode = maketree(VARDECL);
                        addChild(declNode, yyvsp[-6].node);
                        addChild(declNode, maketreeWithVal(IDENTIFIER,saveyylval));
                        addChild(declNode, maketreeWithVal(INTCONSTANT,yylval.val));
                        yyval.node = declNode;
                     }
break;
case 8:
#line 121 "parser.y"
{
                        stupdate(yylval.val, yyvsp[-2].node->val, scope);
						tree *declNode = maketree(VARDECL);
                        addChild(declNode, yyvsp[-2].node);
						stupdate(yylval.val, yyvsp[-2].node->val, scope);
                        addChild(declNode, maketreeWithVal(IDENTIFIER,yylval.val));
                        yyval.node = declNode;
                     }
break;
case 9:
#line 132 "parser.y"
{
                        yyval.node = maketreeWithVal(TYPESPECIFIER, INT);
                     }
break;
case 10:
#line 136 "parser.y"
{
                        yyval.node = maketreeWithVal(TYPESPECIFIER, CHAR);
                     }
break;
case 11:
#line 140 "parser.y"
{
                        yyval.node = maketreeWithVal(TYPESPECIFIER, VOID);
                     }
break;
case 12:
#line 144 "parser.y"
{
                        yyval.node = maketreeWithVal(TYPESPECIFIER, STRING);
                     }
break;
case 13:
#line 149 "parser.y"
{saveyylval = yylval.val; scope++;}
break;
case 14:
#line 150 "parser.y"
{
						stupdate(saveyylval, yyvsp[-6].node->val, scope);
                        tree *functionNode = maketree(FUNDECL);
                        addChild(functionNode, yyvsp[-6].node);
                        addChild(functionNode, maketreeWithVal(IDENTIFIER,saveyylval));
                        addChild(functionNode, yyvsp[-2].node);
                        addChild(functionNode, yyvsp[0].node);
                        yyval.node = functionNode;
                     }
break;
case 15:
#line 159 "parser.y"
{ saveyylval = yylval.val;}
break;
case 16:
#line 160 "parser.y"
{
                        stupdate(saveyylval, yyvsp[-5].node->val, scope);
						tree *functionNode = maketree(FUNDECL);
                        addChild(functionNode, yyvsp[-5].node);
                        addChild(functionNode, maketreeWithVal(IDENTIFIER,saveyylval));
                        addChild(functionNode, yyvsp[0].node);
                        yyval.node = functionNode;
                     }
break;
case 17:
#line 171 "parser.y"
{
                        tree *formalDeclListNode = maketree(FORMALDECLLIST);
                        addChild(formalDeclListNode, yyvsp[0].node);
                        yyval.node = formalDeclListNode;
                     }
break;
case 18:
#line 177 "parser.y"
{
                        tree *formalDeclListNode = maketree(FORMALDECLLIST);
                        addChild(formalDeclListNode, yyvsp[-2].node);
                        addChild(formalDeclListNode, yyvsp[0].node);
                        yyval.node = formalDeclListNode;
                     }
break;
case 19:
#line 186 "parser.y"
{  
						stupdate(yylval.val, yyvsp[-1].node->val, scope);
                        tree *declNode = maketree(FORMALDECL);
                        addChild(declNode, yyvsp[-1].node);
                        addChild(declNode, maketreeWithVal(IDENTIFIER,yylval.val));
                        yyval.node = declNode;
                     }
break;
case 20:
#line 194 "parser.y"
{
                        stupdate(yylval.val, yyvsp[-3].node->val, scope);
						tree *declNode = maketree(FORMALDECL);
                        addChild(declNode, yyvsp[-3].node);
                        addChild(declNode, maketreeWithVal(IDENTIFIER,yylval.val));
                        yyval.node = declNode;
                     }
break;
case 21:
#line 204 "parser.y"
{
                        tree *funBodyNode = maketree(FUNBODY);
                        addChild(funBodyNode, yyvsp[-2].node);
                        addChild(funBodyNode, yyvsp[-1].node);
                        scope--;
						yyval.node = funBodyNode;
                     }
break;
case 22:
#line 214 "parser.y"
{
                        tree *localDeclListNode = maketree(LOCALDECLLIST);
                        yyval.node = localDeclListNode;
                     }
break;
case 23:
#line 219 "parser.y"
{
                        tree *localDeclListNode = maketree(LOCALDECLLIST);
                        addChild(localDeclListNode, yyvsp[-1].node);
                        addChild(localDeclListNode, yyvsp[0].node);
                        yyval.node = localDeclListNode;
                     }
break;
case 24:
#line 228 "parser.y"
{
                        tree *statementNode = maketree(STATEMENTLIST);
                        yyval.node = statementNode;
                     }
break;
case 25:
#line 233 "parser.y"
{
                        tree *statementNode = maketree(STATEMENTLIST);
                        addChild(statementNode, yyvsp[-1].node);
                        addChild(statementNode, yyvsp[0].node);
                        yyval.node = statementNode;
                     }
break;
case 26:
#line 242 "parser.y"
{
                        yyval.node = yyvsp[0].node;
                     }
break;
case 27:
#line 246 "parser.y"
{
                        yyval.node = yyvsp[0].node;
                     }
break;
case 28:
#line 250 "parser.y"
{
                        yyval.node = yyvsp[0].node;
                     }
break;
case 29:
#line 254 "parser.y"
{
                        yyval.node = yyvsp[0].node;
                     }
break;
case 30:
#line 258 "parser.y"
{
                        yyval.node = yyvsp[0].node;
                     }
break;
case 31:
#line 263 "parser.y"
{scope++;}
break;
case 32:
#line 263 "parser.y"
{scope--;}
break;
case 33:
#line 264 "parser.y"
{  
                        tree *compoundStmtNode = maketree(COMPOUNDSTMT);
                        addChild(compoundStmtNode, yyvsp[-2].node);
                        yyval.node = compoundStmtNode;
                     }
break;
case 34:
#line 272 "parser.y"
{
                        tree *assignmentNode = maketree(ASSIGNSTMT);
                        addChild(assignmentNode, yyvsp[-3].node);
                        addChild(assignmentNode, yyvsp[-1].node);
                        yyval.node = assignmentNode;
                     }
break;
case 35:
#line 279 "parser.y"
{
                        tree *assignmentNode = maketree(ASSIGNSTMT);
                        addChild(assignmentNode, yyvsp[-1].node);
                        yyval.node = assignmentNode;
                     }
break;
case 36:
#line 288 "parser.y"
{
                        tree *condNode = maketree(CONDSTMT);
                        addChild(condNode, yyvsp[-2].node);
                        addChild(condNode, yyvsp[0].node);
                        yyval.node = condNode;
                     }
break;
case 37:
#line 295 "parser.y"
{
                        tree *condNode = maketree(CONDSTMT);
                        addChild(condNode, yyvsp[-4].node);
                        addChild(condNode, yyvsp[-2].node);
                        addChild(condNode, yyvsp[0].node);
                        yyval.node = condNode;
                     }
break;
case 38:
#line 305 "parser.y"
{
                        tree *loopNode = maketree(LOOPSTMT);
                        addChild(loopNode, yyvsp[-2].node);
                        addChild(loopNode, yyvsp[0].node);
                        yyval.node = loopNode;
                     }
break;
case 39:
#line 314 "parser.y"
{
                        tree *returnStmtNode = maketree(RETURNSTMT);
                        yyval.node = returnStmtNode;
                     }
break;
case 40:
#line 319 "parser.y"
{
                        tree *returnNode = maketree(RETURNSTMT);
                        addChild(returnNode, yyvsp[-1].node);
                        yyval.node = returnNode;
                     }
break;
case 41:
#line 327 "parser.y"
{
                        yyval.node = maketreeWithVal(IDENTIFIER,yylval.val);
                     }
break;
case 42:
#line 330 "parser.y"
{saveyylval = yylval.val; }
break;
case 43:
#line 331 "parser.y"
{
                        tree *varNode = maketree(VAR);
                        addChild(varNode, maketreeWithVal(IDENTIFIER,saveyylval));
                        addChild(varNode, yyvsp[-1].node);
                        yyval.node = varNode;
                     }
break;
case 44:
#line 340 "parser.y"
{
                        tree *expNode = maketree(EXPRESSION);
                        addChild(expNode, yyvsp[0].node);
                        yyval.node = expNode;
                     }
break;
case 45:
#line 346 "parser.y"
{
                        tree *expNode = maketree(EXPRESSION);
                        addChild(expNode, yyvsp[-2].node);
                        addChild(expNode, yyvsp[-1].node);
                        addChild(expNode, yyvsp[0].node);
                        yyval.node = expNode;
                     }
break;
case 46:
#line 356 "parser.y"
{
                        yyval.node = maketreeWithVal(RELOP,GTE);
                     }
break;
case 47:
#line 360 "parser.y"
{
                        yyval.node = maketreeWithVal(RELOP,GT);
                     }
break;
case 48:
#line 364 "parser.y"
{
                        yyval.node = maketreeWithVal(RELOP,LT);
                     }
break;
case 49:
#line 368 "parser.y"
{
                        yyval.node = maketreeWithVal(RELOP,LTE);
                     }
break;
case 50:
#line 372 "parser.y"
{
                        yyval.node = maketreeWithVal(RELOP,EQ);
                     }
break;
case 51:
#line 376 "parser.y"
{
                        yyval.node = maketreeWithVal(RELOP,NEQ);
                     }
break;
case 52:
#line 382 "parser.y"
{
                        yyval.node = yyvsp[0].node;
                     }
break;
case 53:
#line 386 "parser.y"
{
                        tree *aeNode = maketree(ADDEXPR);
                        addChild(aeNode, yyvsp[-2].node);
                        addChild(aeNode, yyvsp[-1].node);
                        addChild(aeNode, yyvsp[0].node);
                        yyval.node = aeNode;
                     }
break;
case 54:
#line 396 "parser.y"
{
                        yyval.node = maketreeWithVal(ADDOP,ADD);
                     }
break;
case 55:
#line 400 "parser.y"
{
                        yyval.node = maketreeWithVal(ADDOP,SUB);
                     }
break;
case 56:
#line 406 "parser.y"
{
                        yyval.node = yyvsp[0].node;
                     }
break;
case 57:
#line 410 "parser.y"
{
                        tree *termNode = maketree(TERM);
                        addChild(termNode, yyvsp[-2].node);
                        addChild(termNode, yyvsp[-1].node);
                        addChild(termNode, yyvsp[0].node);
                        yyval.node = termNode;
                     }
break;
case 58:
#line 420 "parser.y"
{
                        yyval.node = maketreeWithVal(MULOP,MUL);
                     }
break;
case 59:
#line 424 "parser.y"
{
                        yyval.node = maketreeWithVal(MULOP,DIV);
                     }
break;
case 60:
#line 430 "parser.y"
{
                        yyval.node = yyvsp[-1].node;
                     }
break;
case 61:
#line 434 "parser.y"
{
                        yyval.node = yyvsp[0].node;
                     }
break;
case 62:
#line 438 "parser.y"
{
                        yyval.node = yyvsp[0].node;
                     }
break;
case 63:
#line 442 "parser.y"
{
                        yyval.node = maketreeWithVal(INTCONSTANT, yylval.val);
                     }
break;
case 64:
#line 446 "parser.y"
{
                        yyval.node = maketreeWithVal(CHARCONSTANT, yylval.val);
                     }
break;
case 65:
#line 450 "parser.y"
{
                        yyval.node = maketreeWithVal(STRCONSTANT, yylval.val);
                     }
break;
case 66:
#line 455 "parser.y"
{
                        tree *funcCall = maketree(FUNCCALLEXPR);
                        addChild(funcCall, maketreeWithVal(IDENTIFIER, yylval.val));
                        addChild(funcCall, yyvsp[-1].node);
                        yyval.node = funcCall;
                     }
break;
case 67:
#line 462 "parser.y"
{
                        tree *funcCall = maketree(FUNCCALLEXPR);
                        addChild(funcCall, maketreeWithVal(IDENTIFIER, yylval.val));
                        yyval.node = funcCall;
                     }
break;
case 68:
#line 470 "parser.y"
{
                        tree *argList = maketree(ARGLIST);
                        addChild(argList, yyvsp[0].node);
                        yyval.node = argList;
                     }
break;
case 69:
#line 476 "parser.y"
{
                        tree *argList = maketree(ARGLIST);
                        addChild(argList, yyvsp[-2].node);
                        addChild(argList, yyvsp[0].node);
                        yyval.node = argList;
                     }
break;
#line 1038 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
