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
typedef union
{
   int val;
   char *str;
   struct treenode *node;
} YYSTYPE;
extern YYSTYPE yylval;
