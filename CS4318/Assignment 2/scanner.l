  /*
     scanner.l
     
     flex descriptor file for lexical scanner

     Project 1  CS 4318  Spring 2010
     	Updated for Spring 2013

     Christopher Shaltz

  */

  /* definitions */
 #include "y.tab.h"
 #include "string.h"
 #include "hash.h"
 
%{
int hashAString (const char *symbol);
int hashAString (const char *symbol, int type, int scope);
  
  /* globals */
  int yycolumn = 1;     /* line & column for error reporting */
  int yyline = 1;
  
  int yycolumn2, yyline2;   /* temps for above */
   
  int errors = 0;

  char stringbuffer[81];    /* for string literals */
  int stringlength = 0;
  
  char unksymerrmsg[] = "Unknown symbol '~'";
  

%}


DIGIT       [0-9]
DIGITS      [0-9]*
NZDIGIT     [1-9]
NZDIGITS    [1-9]*


  /* start conditions for special states */
%x string_literal


%%



  /* rules */

  /* constants */
0                   { yycolumn += yyleng; yylval.val = 0; return INTCONST;}
{NZDIGIT}{DIGITS}*  { yycolumn += yyleng; yylval.val = atoi (yytext); return INTCONST;}
'.'                 { yycolumn += yyleng; yylval.val = yytext[1]; return CHARCONST;}
'\\.'   {
            char look1 = yytext[2];
            switch (look1)
            {
            case 'n':
                yylval.val = '\n';
                break;
            case 't':
                yylval.val = '\t';
                break;
            case '\\':
                yylval.val = '\\';
                break;
            case '\"':
                yylval.val = '\"';
                break;
            case '\'':
                yylval.val = '\'';
                break;
            case '0':
                yylval.val = '\0';
                break;
            default:
                yyerror ("Invalid character constant");
                yylval.val = -256;          /* placeholder for bad escape character */
            }
            yycolumn += yyleng;
            return CHARCONST;
        }
        
\"      {   /* start of a string literal */

            stringbuffer[0] = '\0';
            stringlength = 0;
            
            yycolumn2 = yycolumn;

            BEGIN (string_literal);
        }

<string_literal>\\\\    { yycolumn2 += yyleng; stringbuffer[stringlength++] = '\\'; }
<string_literal>\\n     { yycolumn2 += yyleng; stringbuffer[stringlength++] = '\n'; }
<string_literal>\\t     { yycolumn2 += yyleng; stringbuffer[stringlength++] = '\t'; }
<string_literal>\\\"    { yycolumn2 += yyleng; stringbuffer[stringlength++] = '\"'; }
<string_literal>\"      {   /* terminating double quote */
                            BEGIN (INITIAL);
                            yycolumn2 += yyleng;
                            yycolumn = yycolumn2;
                            stringbuffer[stringlength] = '\0';
                            
                            /* add to string / symbol table */
                            yylval.val = hashAString (stringbuffer);
                            return STRCONST;
                        }
<string_literal>\n      {
                            yyerror ("Unterminated string constant");
                            ++yyline;
                            yycolumn = 1;
                            BEGIN (INITIAL);
                        }
<string_literal>.       {
                            yycolumn2 += yyleng;
                            stringbuffer[stringlength++] = yytext[0];
                        }


  /* keywords */

if     { yycolumn += yyleng; return KWD_IF; }
else   { yycolumn += yyleng; return KWD_ELSE; }
while  { yycolumn += yyleng; return KWD_WHILE; }
int    { yycolumn += yyleng; return KWD_INT; }
string { yycolumn += yyleng; return KWD_STRING; }
char   { yycolumn += yyleng; return KWD_CHAR; }
return { yycolumn += yyleng; return KWD_RETURN; }
void   { yycolumn += yyleng; return KWD_VOID; }


  /* operators */
\+   { yycolumn += yyleng; return OPER_ADD; }
-    { yycolumn += yyleng; return OPER_SUB; }
\*   { yycolumn += yyleng; return OPER_MUL; }
\/   { yycolumn += yyleng; return OPER_DIV; }
\<   { yycolumn += yyleng; return OPER_LT; }
>    { yycolumn += yyleng; return OPER_GT; }
>=   { yycolumn += yyleng; return OPER_GTE; }
\<=  { yycolumn += yyleng; return OPER_LTE; }
==   { yycolumn += yyleng; return OPER_EQ; }
!=   { yycolumn += yyleng; return OPER_NEQ; }
=    { yycolumn += yyleng; return OPER_ASGN; }


  /* brackets & parens */
"["  { yycolumn += yyleng; return LSQ_BRKT; }
]    { yycolumn += yyleng; return RSQ_BRKT; }
\{   { yycolumn += yyleng; return LCRLY_BRKT; }
\}   { yycolumn += yyleng; return RCRLY_BRKT; }
\(   { yycolumn += yyleng; return LPAREN; }
\)   { yycolumn += yyleng; return RPAREN; }


  /* punctuation */
,  { yycolumn += yyleng; return COMMA; }
;  { yycolumn += yyleng; return SEMICLN; }


  /* identifiers */
[a-zA-Z][0-9a-zA-Z]*    {
                            /* send to symbol table,
                                add if not present. */
                            yylval.val = hashAString (yytext);
                            
                            yycolumn += yyleng;
                            /*printf ("**DEBUG: ID exit, hash: %d.**\n", yylval);*/

                            return ID;
                        }   /* end of identifiers action block */


  /* block comments (possibly nested n levels deep) */
"/*"  {
        char look1, look2;
        int flag = 1;
        int depth = 1;
        
        int yycommcolumn = yycolumn + yyleng;
        int yycommline = yyline;
        
        look1 = input ();
        ++yycommcolumn;
        if (look2 < 0)
            flag = 0;       /* bail if EOF */

        while (flag)
        {
            if (look1 == '/')       /* possible left bookend */
            {
                look2 = input ();
                ++yycommcolumn;
                if (look2 < 0)
                    flag = 0;       /* bail if EOF in a comment */
                
                /* going deeper? */
                if (look2 == '*')
                    ++depth;
                else
                    look1 = look2;
            }
            else if (look1 == '*')  /* possible right bookend */
            {
                look2 = input ();
                ++yycommcolumn;
                if (look2 < 0)
                    flag = 0;       /* bail if EOF in a comment */

                /* going back up? */
                if (look2 == '/')
                {
                    --depth;
                    if (depth < 1)
                        flag = 0;
                }
                else
                    look1 = look2;
            }
            else  /* just more comment text */
            {
                if (look1 == '\n')
                {
                    ++yycommline;
                    yycommcolumn = 1;
                }
                
                look1 = input ();
                ++yycommcolumn;
                if (look1 < 0)
                    flag = 0;       /* bail if EOF in a comment */
            }
        } /* end while */
        
        /* if we didn't wrap up all comment levels: error */
        if (depth != 0)
            yyerror ("Unterminated comment block");
        
        /* and update line & column post-somment */
        yyline = yycommline;
        yycolumn = yycommcolumn;
        
      } /* end action for comment block */


  /* white space */

\t     { ++yycolumn; /* skip over a TAB character */ }
\40    { ++yycolumn; /* skip over a SPACE character */ }
\15    { /* harmlessly eat a CR character */ }
\12    { ++yyline;  yycolumn = 1; /* track LF and eat it */ }


  /* and final catch-all we found a character that doesn't match to anything */
.      { unksymerrmsg[16] = yytext[0]; yyerror (unksymerrmsg); yycolumn += yyleng; }



%%


  /* code */

/* print out an error message as helpfully as we can */
void yyerror (const char *message)
{
    printf ("\n%s at line: %d column: %d.\n", message, yyline, yycolumn);
    ++errors;
}


