/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
#line 24 "parser.y"

   int val;
   char *str;
   struct treenode *node;



/* Line 2068 of yacc.c  */
#line 130 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


