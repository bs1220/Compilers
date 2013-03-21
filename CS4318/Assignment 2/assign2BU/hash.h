#ifndef HASHH
#define HASHH

#include <string.h>
void yyerror (const char *message);
int hashAString (const char *symbol);
int calcHash (const char *strx);
void clearSymbols ();
void dumpSymbols ();
void stupdate(int hash, int type, int scope);

  /* hash table for identifiers and string literals */
typedef struct Table{
	char *string;
	int type;
	int scope;}Table;
  
  Table *symbolTable[10000];
  extern const int tableSize;
  
/* insert string into symbol table
        returns index if inserted or already present
        or -1 if something failed */

#endif