/*** Definition section ***/

%option yylineno

%{
#include <tokendef.h>
#include <stdio.h>

char buff[1000];
int col = 1;
int str_col;
int str_row;
int yylval;
char *yptr;
int buff_len;

%}

IDS			[a-zA-Z][a-zA-Z0-9]*
INT			([1-9][0-9]*)|0
CHARCNST	"\'"."\'"
MULTCOMM	"/*"([^\*]|\*[^/])"*/"
CHARCNSTERR	"\'".[^/']+"\'"
STRGCNSTERR	\".
MULTCOMMERR	"/*"([^\*]|\*[^/])
WHTSPC		[\t\r\n ]+


/* state def */

%X STR

%%

\" 					{ BEGIN(STR); buff_len = 0;  }    
<STR>[^\\\n\\\"]*       { yptr= yytext; while ( *yptr ) buff[buff_len++] = *yptr++; }	 
<STR>\n       			{ return ERROR; }
<STR>\\[0-9]+ 			{ return ERROR; }
<STR>\\n 				{ buff[buff_len++] = '\n'; }
<STR>\\t  				{ buff[buff_len++] = '\t'; }
<STR>\\r  				{ buff[buff_len++] = '\r'; }
<STR>\\b  				{ buff[buff_len++] = '\b'; }
<STR>\\f  				{ buff[buff_len++] = '\f'; }
<STR>\\\"				{ buff[buff_len++] = '\"'; }
<STR>\\\\				{ buff[buff_len++] = '\\'; }		 
<STR>\"        			{ BEGIN(INITIAL); buff[buff_len++] = '\0'; return STRCONST; }

    /* Reserved words */
"if"	    { return KWD_IF; }
"int"       { return KWD_INT; } 
"else"      { return KWD_ELSE; }
"while"     { return KWD_WHILE; }
"string"    { return KWD_STRING; }
"char"      { return KWD_CHAR; }
"return"    { return KWD_RETURN; }
"void"      { return KWD_VOID; }


 /* Operators and Special symbols */
"+"         { return OPER_ADD; }
"-"         { return OPER_SUB; }
"*"         { return OPER_MUL; }
"/"         { return OPER_DIV; }
"<"         { return OPER_LT; }
">"         { return OPER_GT; }
"<="        { return OPER_LTE; }
">="        { return OPER_GTE; }
"=="        { return OPER_EQ; }
"!="        { return OPER_NEQ; }
"="         { return OPER_ASGN; }
"["         { return LSQ_BRKT; }
"]"         { return RSQ_BRKT; }
"{"         { return LCRLY_BRKT; }
"}"         { return RCRLY_BRKT; }
"("         { return LPAREN; }
")"         { return RPAREN; }
","         { return COMMA; }
";"         { return SEMICLN; }


{IDS}			{ strcpy (buff, yytext); return ID; }
{INT}			{ yylval = atoi(yytext); return INTCONST; }
{CHARCNST}		{ yylval = ( int ) yytext[1]; return CHARCONST; }
{CHARCNSTERR}	{printf ("ERROR NOT A CHAR @ LINE %i\n" , yylineno); }
{MULTCOMMERR}	{printf ("ERROR NOT A Multiline Comment unterminated @ LINE %i\n", yylineno); }
{WHTSPC}		{}
{MULTCOMM}		{}
.	  	  	{ return ILLEGAL_TOK; }


%%