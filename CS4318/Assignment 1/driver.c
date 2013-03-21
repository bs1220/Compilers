#include "tokendef.h"
#include <stdio.h>

extern yylineno;
extern yycol;
extern yytext;
extern int yylval;
extern char buff[1000];


/* major stuff */
printToken(int tokenNum){
  switch(tokenNum){
	case  ID :
		printf("<%s, IDENTIFIER>\n", buff);
        break;
	case  INTCONST :
		printf("<%i, INTEGER>\n", yylval);
        break;
	case  CHARCONST :
		printf("<%c, CHAR>\n", yylval);
        break;
	case  STRCONST :
		printf("<%s, STRING>\n", buff);
        break;

/* keywords */
	case  KWD_IF: 
		printf("<IF, KEYWORD>\n");
        break;
	case  KWD_ELSE:
		printf("<ELSE, KEYWORD>\n");
        break;
	case  KWD_WHILE:
		printf("<WHILE, KEYWORD>\n");
        break;
	case  KWD_INT:
		printf("<INT, KEYWORD>\n");
        break;
	case  KWD_STRING:
		printf("<STRING, KEYWORD>\n");
        break;
	case  KWD_CHAR:
		printf("<CHAR, KEYWORD>\n");
        break;
	case  KWD_RETURN:
		printf("<RETURN, KEYWORD>\n");
        break;
	case  KWD_VOID:
		printf("<VOID, KEYWORD>\n");
        break;

/*OPERATORS*/
	 case OPER_ADD:
        printf("<ADD, OPERATOR>\n");
        break;
     case OPER_SUB:
        printf("<SUB, OPERATOR>\n");
        break;                 
     case OPER_MUL:
        printf("<MUL, OPERATOR>\n");
        break;
     case OPER_DIV:
        printf("<DIV, OPERATOR>\n");
        break;     
     case OPER_LT:
        printf("<LT, OPERATOR>\n");
        break;
     case OPER_GT:
        printf("<GT, OPERATOR>\n");
        break;                 
     case OPER_GTE:
        printf("<GTE, OPERATOR>\n");
        break;
     case OPER_LTE:
        printf("<LTE, OPERATOR>\n");
        break;     
     case OPER_EQ:
        printf("<EQ, OPERATOR>\n");
        break;                 
     case OPER_NEQ:
        printf("<NEQ, OPERATOR>\n");
        break;
     case OPER_ASGN:
        printf("<ASGN, OPERATOR>\n");
        break;


	case  LSQ_BRKT:
		printf("<LSQ, OPERATOR>\n");
        break;
	case  RSQ_BRKT:
		printf("<RSQ, OPERATOR>\n");
        break;
	case  LCRLY_BRKT:
		printf("<LCRLY, OPERATOR>\n");
        break;
	case  RCRLY_BRKT:
		printf("<RCRLY, OPERATOR>\n");
        break;
	case  LPAREN:
		printf("<LPAREN, OPERATOR>\n");
        break;
	case  RPAREN:
		printf("<RPAREN, OPERATOR>\n");
        break;


	case  COMMA:
		printf("<COMMA, PUNCTUATION>\n");
        break;
	case  SEMICLN:
		printf("<SEMICLN, PUNCTUATION>\n");
        break;

	case  ILLEGAL_TOK:
		printf("<ILLEGAL_TKN, TOKEN>\n");
        break;
	case  ERROR:
		printf("<ERROR, ERROR>\n");
        break;
}}

int main() {

  int ret = yylex();
  while (ret) {
    printToken(ret);
    ret = yylex();    
  }
  return 0;
}
	