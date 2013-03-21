%{
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
%}

%union
{
   int val;
   char *str;
   struct treenode *node;
}


%token <val> ID
%token <val> INTCONST
%token <val> CHARCONST
%token <val> STRCONST
%token <val> KWD_IF
%token <val> KWD_ELSE
%token <val> KWD_WHILE
%token <val> KWD_INT
%token <val> KWD_STRING
%token <val> KWD_CHAR
%token <val> KWD_RETURN
%token <val> KWD_VOID
%token <val> OPER_ADD
%token <val> OPER_SUB
%token <val> OPER_MUL
%token <val> OPER_DIV
%token <val> OPER_LT
%token <val> OPER_GT
%token <val> OPER_GTE
%token <val> OPER_LTE
%token <val> OPER_EQ
%token <val> OPER_NEQ
%token <val> OPER_ASGN
%token <val> LSQ_BRKT
%token <val> RSQ_BRKT
%token <val> LCRLY_BRKT
%token <val> RCRLY_BRKT
%token <val> LPAREN
%token <val> RPAREN
%token <val> COMMA
%token <val> SEMICLN
%token <val> ILLEGAL_TOK
%token <val> ERROR

%nonassoc XIF
%nonassoc KWD_ELSE

%type <node> program declList decl varDecl typeSpecifier funDecl formalDeclList formalDecl funBody localDeclList statementList statement compoundStmt assignStmt condStmt loopStmt returnStmt var expression relop addExpr addop term mulop factor funcCallExpr argList

%start program

%%

program           :  declList
                     {
                        tree *progNode = maketree(PROGRAM);
                        addChild(progNode, $1);
                        AST = progNode;
                     }
                  ;

declList          :  decl
                     {
                        tree *declListNode = maketree(DECLLIST);
                        addChild(declListNode, $1);
                        $$ = declListNode;
                     }
                  |  declList decl
                     {
                        tree *declListNode = maketree(DECLLIST);
                        addChild(declListNode, $1);
                        addChild(declListNode, $2);
                        $$ = declListNode;
                     }
                  ;

decl              :  varDecl
                     {
                        tree *declNode = maketree(DECL);
                        addChild(declNode, $1);
                        $$ = declNode;
                     }
                  |  funDecl
                     {
                        tree *declNode = maketree(DECL);
                        addChild(declNode, $1);
                        $$ = declNode;
                     }
                  ;

varDecl           :  typeSpecifier ID LSQ_BRKT {saveyylval = yylval.val;} INTCONST RSQ_BRKT SEMICLN
                     {
                        stupdate(saveyylval, $1->val, scope);
                        tree *declNode = maketree(VARDECL);
                        addChild(declNode, $1);
                        addChild(declNode, maketreeWithVal(IDENTIFIER,saveyylval));
                        addChild(declNode, maketreeWithVal(INTCONSTANT,yylval.val));
                        $$ = declNode;
                     }
                  |  typeSpecifier ID SEMICLN
                     {
                        stupdate(yylval.val, $1->val, scope);
						tree *declNode = maketree(VARDECL);
                        addChild(declNode, $1);
						stupdate(yylval.val, $1->val, scope);
                        addChild(declNode, maketreeWithVal(IDENTIFIER,yylval.val));
                        $$ = declNode;
                     }
                  ;

typeSpecifier     :  KWD_INT
                     {
                        $$ = maketreeWithVal(TYPESPECIFIER, INT);
                     }
                  |  KWD_CHAR
                     {
                        $$ = maketreeWithVal(TYPESPECIFIER, CHAR);
                     }
                  |  KWD_VOID
                     {
                        $$ = maketreeWithVal(TYPESPECIFIER, VOID);
                     }
                  |  KWD_STRING
                     {
                        $$ = maketreeWithVal(TYPESPECIFIER, STRING);
                     }
                  ;

funDecl           :  typeSpecifier ID LPAREN {saveyylval = yylval.val; scope++;} formalDeclList RPAREN funBody
                     {
						stupdate(saveyylval, $1->val, scope);
                        tree *functionNode = maketree(FUNDECL);
                        addChild(functionNode, $1);
                        addChild(functionNode, maketreeWithVal(IDENTIFIER,saveyylval));
                        addChild(functionNode, $5);
                        addChild(functionNode, $7);
                        $$ = functionNode;
                     }
                  |  typeSpecifier ID LPAREN RPAREN { saveyylval = yylval.val;} funBody
                     {
                        stupdate(saveyylval, $1->val, scope);
						tree *functionNode = maketree(FUNDECL);
                        addChild(functionNode, $1);
                        addChild(functionNode, maketreeWithVal(IDENTIFIER,saveyylval));
                        addChild(functionNode, $6);
                        $$ = functionNode;
                     }
                  ;

formalDeclList    :  formalDecl
                     {
                        tree *formalDeclListNode = maketree(FORMALDECLLIST);
                        addChild(formalDeclListNode, $1);
                        $$ = formalDeclListNode;
                     }
                  |  formalDecl COMMA formalDeclList
                     {
                        tree *formalDeclListNode = maketree(FORMALDECLLIST);
                        addChild(formalDeclListNode, $1);
                        addChild(formalDeclListNode, $3);
                        $$ = formalDeclListNode;
                     }
                  ;

formalDecl        :  typeSpecifier ID
                     {
						stupdate(yylval.val, $1->val, scope);
                        tree *declNode = maketree(FORMALDECL);
                        addChild(declNode, $1);
                        addChild(declNode, maketreeWithVal(IDENTIFIER,yylval.val));
                        $$ = declNode;
                     }
                  |  typeSpecifier ID LSQ_BRKT RSQ_BRKT
                     {
                        stupdate(yylval.val, $1->val, scope);
						tree *declNode = maketree(FORMALDECL);
                        addChild(declNode, $1);
                        addChild(declNode, maketreeWithVal(IDENTIFIER,yylval.val));
                        $$ = declNode;
                     }
                  ;

funBody           :  LCRLY_BRKT  localDeclList statementList RCRLY_BRKT
                     {
                        tree *funBodyNode = maketree(FUNBODY);
                        addChild(funBodyNode, $2);
                        addChild(funBodyNode, $3);
                        scope--;
						$$ = funBodyNode;
                     }
                  ;

localDeclList     :
                     {
                        tree *localDeclListNode = maketree(LOCALDECLLIST);
                        $$ = localDeclListNode;
                     }
                  |  varDecl localDeclList
                     {
                        tree *localDeclListNode = maketree(LOCALDECLLIST);
                        addChild(localDeclListNode, $1);
                        addChild(localDeclListNode, $2);
                        $$ = localDeclListNode;
                     }
                  ;

statementList     :
                     {
                        tree *statementNode = maketree(STATEMENTLIST);
                        $$ = statementNode;
                     }
                  |  statement statementList
                     {
                        tree *statementNode = maketree(STATEMENTLIST);
                        addChild(statementNode, $1);
                        addChild(statementNode, $2);
                        $$ = statementNode;
                     }
                  ;

statement         :  compoundStmt
                     {
                        $$ = $1;
                     }
                  |  assignStmt
                     {
                        $$ = $1;
                     }
                  |  condStmt
                     {
                        $$ = $1;
                     }
                  |  loopStmt
                     {
                        $$ = $1;
                     }
                  |  returnStmt
                     {
                        $$ = $1;
                     }
                  ;

compoundStmt      : LCRLY_BRKT {scope++;} statementList {scope--;} RCRLY_BRKT
                     {
                        tree *compoundStmtNode = maketree(COMPOUNDSTMT);
                        addChild(compoundStmtNode, $3);
                        $$ = compoundStmtNode;
                     }
                  ;

assignStmt        :  var OPER_ASGN expression SEMICLN
                     {
                        tree *assignmentNode = maketree(ASSIGNSTMT);
                        addChild(assignmentNode, $1);
                        addChild(assignmentNode, $3);
                        $$ = assignmentNode;
                     }
                  |  expression SEMICLN
                     {
                        tree *assignmentNode = maketree(ASSIGNSTMT);
                        addChild(assignmentNode, $1);
                        $$ = assignmentNode;
                     }
                  ;


condStmt          :  KWD_IF LPAREN expression RPAREN statement %prec XIF
                     {
                        tree *condNode = maketree(CONDSTMT);
                        addChild(condNode, $3);
                        addChild(condNode, $5);
                        $$ = condNode;
                     }
                  |  KWD_IF LPAREN expression RPAREN statement KWD_ELSE statement
                     {
                        tree *condNode = maketree(CONDSTMT);
                        addChild(condNode, $3);
                        addChild(condNode, $5);
                        addChild(condNode, $7);
                        $$ = condNode;
                     }
                  ;

loopStmt          :  KWD_WHILE LPAREN expression RPAREN statement
                     {
                        tree *loopNode = maketree(LOOPSTMT);
                        addChild(loopNode, $3);
                        addChild(loopNode, $5);
                        $$ = loopNode;
                     }
                  ;

returnStmt        :  KWD_RETURN SEMICLN
                     {
                        tree *returnStmtNode = maketree(RETURNSTMT);
                        $$ = returnStmtNode;
                     }
                  |  KWD_RETURN expression SEMICLN
                     {
                        tree *returnNode = maketree(RETURNSTMT);
                        addChild(returnNode, $2);
                        $$ = returnNode;
                     }
                  ;

var               :  ID
                     {
                        $$ = maketreeWithVal(IDENTIFIER,yylval.val);
                     }
                  |  ID LSQ_BRKT {saveyylval = yylval.val; } addExpr RSQ_BRKT
                     {
                        tree *varNode = maketree(VAR);
                        addChild(varNode, maketreeWithVal(IDENTIFIER,saveyylval));
                        addChild(varNode, $4);
                        $$ = varNode;
                     }
                  ;

expression        :  addExpr
                     {
                        tree *expNode = maketree(EXPRESSION);
                        addChild(expNode, $1);
                        $$ = expNode;
                     }
                  |  expression relop addExpr
                     {
                        tree *expNode = maketree(EXPRESSION);
                        addChild(expNode, $1);
                        addChild(expNode, $2);
                        addChild(expNode, $3);
                        $$ = expNode;
                     }
                  ;

relop             :  OPER_GTE
                     {
                        $$ = maketreeWithVal(RELOP,GTE);
                     }
                  |  OPER_GT
                     {
                        $$ = maketreeWithVal(RELOP,GT);
                     }
                  |  OPER_LT
                     {
                        $$ = maketreeWithVal(RELOP,LT);
                     }
                  |  OPER_LTE
                     {
                        $$ = maketreeWithVal(RELOP,LTE);
                     }
                  |  OPER_EQ
                     {
                        $$ = maketreeWithVal(RELOP,EQ);
                     }
                  |  OPER_NEQ
                     {
                        $$ = maketreeWithVal(RELOP,NEQ);
                     }
                  ;

addExpr           :  term
                     {
                        $$ = $1;
                     }
                  |  addExpr addop term
                     {
                        tree *aeNode = maketree(ADDEXPR);
                        addChild(aeNode, $1);
                        addChild(aeNode, $2);
                        addChild(aeNode, $3);
                        $$ = aeNode;
                     }
                  ;

addop             :  OPER_ADD
                     {
                        $$ = maketreeWithVal(ADDOP,ADD);
                     }
                  |  OPER_SUB
                     {
                        $$ = maketreeWithVal(ADDOP,SUB);
                     }
                  ;

term              :  factor
                     {
                        $$ = $1;
                     }
                  |  term mulop factor
                     {
                        tree *termNode = maketree(TERM);
                        addChild(termNode, $1);
                        addChild(termNode, $2);
                        addChild(termNode, $3);
                        $$ = termNode;
                     }
                  ;

mulop             :  OPER_MUL
                     {
                        $$ = maketreeWithVal(MULOP,MUL);
                     }
                  |  OPER_DIV
                     {
                        $$ = maketreeWithVal(MULOP,DIV);
                     }
                  ;

factor            :  LPAREN expression RPAREN
                     {
                        $$ = $2;
                     }
                  |  var
                     {
                        $$ = $1;
                     }
                  |  funcCallExpr
                     {
                        $$ = $1;
                     }
                  |  INTCONST
                     {
                        $$ = maketreeWithVal(INTCONSTANT, yylval.val);
                     }
                  |  CHARCONST
                     {
                        $$ = maketreeWithVal(CHARCONSTANT, yylval.val);
                     }
                  |  STRCONST
                     {
                        $$ = maketreeWithVal(STRCONSTANT, yylval.val);
                     }

funcCallExpr      :  ID LPAREN {saveyylval = yylval.val;} argList RPAREN
                     {
                        tree *funcCall = maketree(FUNCCALLEXPR);
                        addChild(funcCall, maketreeWithVal(IDENTIFIER, saveyylval));
                        addChild(funcCall, $4);
                        $$ = funcCall;
                     }
                  |  ID LPAREN RPAREN
                     {
                        tree *funcCall = maketree(FUNCCALLEXPR);
                        addChild(funcCall, maketreeWithVal(IDENTIFIER, yylval.val));
                        $$ = funcCall;
                     }
                  ;

argList           :  expression
                     {
                        tree *argList = maketree(ARGLIST);
                        addChild(argList, $1);
                        $$ = argList;
                     }
                  |  argList COMMA expression
                     {
                        tree *argList = maketree(ARGLIST);
                        addChild(argList, $1);
                        addChild(argList, $3);
                        $$ = argList;
                     }
                  ;

%%



int main() {
  if (!yyparse()){
    printAst(AST, 1);
  }
  return 0;
}
