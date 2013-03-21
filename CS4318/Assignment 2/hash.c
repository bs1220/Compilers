#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "hash.h"

const int tableSize = 10000;

int hashAString (const char *symbol)
{
    int hashCode;
    int initialCode;
    Table *node = (Table *)malloc(sizeof(Table));
		/* allocate space for new symbol */
	node->string = (char *)malloc(strlen(symbol));
    

    
    if (symbol)
    {
        /* attempt to place in table */
        
        strcpy (node->string, symbol);
        hashCode = calcHash (symbol);
        /*printf ("**DEBUG: ID: '%s'. **\n", symbol);*/
    
        if ( !(symbolTable[hashCode]) )
        {
            /* found open spot on first try */
            
            symbolTable[hashCode] = node;
        }
        else
        {
            /* initial position was occupied, check if match */
            
            if (strcmp (symbolTable[hashCode]->string, symbol) == 0)
                return hashCode;
            
            
            /* not a match, so try linear probing */
            
            initialCode = hashCode;
            ++hashCode;
            
            while (symbolTable[hashCode] && hashCode != initialCode)
            {
                /* if we find a match, return its code */
                if (strcmp (symbolTable[hashCode]->string, symbol) == 0 && symbolTable[hashCode]->type != type && symbolTable[hashCode]->scope != scope)
                    return hashCode;
                
                /* otherwise, keep looking */
                hashCode = (hashCode + 1) % tableSize;
            }
            
            if (hashCode != initialCode)
            {
                /* we found an open position */
                
                symbolTable[hashCode] = node;
            }
            else
            {
                /* we wrapped all the way around to the beginning
                        with no matches and no open positions */
                
                yyerror ("Symbol table overflow");
                hashCode = -1;
            }
        }
    }
    else
    {
        /* malloc() call failed */
        
        yyerror ("Out of memory");
        hashCode = -1;
    }
    
    return hashCode;
} /* end of hashAString() */

int hashAString (const char *symbol, int type, int scope)
{
    int hashCode;
    int initialCode;
    Table *node = (Table *)malloc(sizeof(Table));
		/* allocate space for new symbol */
	node->string = (char *)malloc(strlen(symbol));
    

    
    if (symbol)
    {
        /* attempt to place in table */
        
        strcpy (node->string, symbol);
        hashCode = calcHash (symbol);
        /*printf ("**DEBUG: ID: '%s'. **\n", symbol);*/
    
        if ( !(symbolTable[hashCode]) )
        {
            /* found open spot on first try */
            
            symbolTable[hashCode] = node;
        }
        else
        {
            /* initial position was occupied, check if match */
            
            if (strcmp (symbolTable[hashCode]->string, symbol) == 0)
                return hashCode;
            
            
            /* not a match, so try linear probing */
            
            initialCode = hashCode;
            ++hashCode;
            
            while (symbolTable[hashCode] && hashCode != initialCode)
            {
                /* if we find a match, return its code */
                if (strcmp (symbolTable[hashCode]->string, symbol) == 0 && symbolTable[hashCode]->type != type && symbolTable[hashCode]->scope != scope)
                    return hashCode;
                
                /* otherwise, keep looking */
                hashCode = (hashCode + 1) % tableSize;
            }
            
            if (hashCode != initialCode)
            {
                /* we found an open position */
                
                symbolTable[hashCode] = node;
            }
            else
            {
                /* we wrapped all the way around to the beginning
                        with no matches and no open positions */
                
                yyerror ("Symbol table overflow");
                hashCode = -1;
            }
        }
    }
    else
    {
        /* malloc() call failed */
        
        yyerror ("Out of memory");
        hashCode = -1;
    }
    
    return hashCode;
} /* end of hashAString() */


/* hash function for strings */
/* hash computation adapted from Roger Priebe's CS3358 class www.cs.txstate.edu/~rp44 */
int calcHash (const char *strx)
{
    int length = strlen (strx);
    unsigned long total = 0;
    int i;
    int p = 1;
    
    for (i = 0; i < length; ++i)
    {
        total += strx[length-i-1] * p;
        p *= 37;
    }
    
    /*printf ("**Hashed '%s' to get %d.**\n", strx, total % tableSize);*/
    
    return total % tableSize;
}


/* free all memory used by symbol table */
void clearSymbols ()
{
    int i;
    for (i = 0; i < tableSize; ++i)
    {
        if (symbolTable[i])
            free (symbolTable[i]);
    }
}


/* dump all symbols in table */
void dumpSymbols ()
{
    int i;
    for (i = 0; i < tableSize; ++i)
    {
        if (symbolTable[i])
            printf ("Symbol %i: \t\"%s\"\n", i, symbolTable[i]);
    }
}


void stupdate(int hash, int type, int scope){
symbolTable[hash]->type = type;
symbolTable[hash]->scope = scope;
}