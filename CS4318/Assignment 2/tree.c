#include<tree.h>
#include<stdio.h>
#include<stdlib.h>
#include "hash.h"

/* string values for ast node types, makes tree output more readable */
char *nodeNames[31] = {"PROGRAM", "DECLLIST", "DECL", "VARDECL", "TYPESPECIFIER", "FUNDECL", "FORMALDECLLIST", "FORMALDECL","FUNBODY", "LOCALDECLLIST", "STATEMENTLIST", "STATEMENT", "COMPOUNDSTMT", "ASSIGNSTMT", "CONDSTMT", "LOOPSTMT", "RETURNSTMT", "VAR", "EXPRESSION", "RELOP", "ADDEXPR", "ADDOP", "TERM", "MULOP", "FACTOR", "FUNCCALLEXPR", "ARGLIST", "IDENTIFIER", "INTCONSTANT", "CHARCONSTANT", "STRCONSTANT"};

char *opNames[11] = {"ADD", "SUB", "MUL", "DIV", "LTE", "GTE", "EQ", "NEQ", "ASGN", "LT", "GT"};

tree *maketree(int kind) {
  tree *this = (tree *) malloc(sizeof(struct treenode));
  this->nodeKind = kind;
  this->numChildren = 0;
  return this;

}

tree *maketreeWithVal(int kind, int val) {
  tree *this = (tree *) malloc(sizeof(struct treenode));
  this->nodeKind = kind;
  this->numChildren = 0;
  this->val = val;
  return this;

}

void addChild(tree *parent, tree *child) {
  if (parent->numChildren == MAXCHILDREN) {
    printf("Cannot add child to parent node\n");
    exit(1);
  }
  nextAvailChild(parent) = child;
  parent->numChildren++;
}

void printAst(tree *node, int nestLevel) {
  if (node != 0){
  	//typespec
  	if (node->nodeKind == 4) {
     		printf("%s,%i\n", nodeNames[node->nodeKind], node->val);
  	}//IDS
  	else if (node->nodeKind == 27){
      		//if (node->val != 0)
         		printf("%s: %s\n", nodeNames[node->nodeKind], symbolTable[node->val]->string);
      		//else
         	//	printf("Illegal ID Found, the token is null!\n");
   	}//CONSTS
   	else if (node->nodeKind == 30)
      		printf("%s: %i\n", nodeNames[node->nodeKind], node->val);
   	else if (node->nodeKind == 29)
      		printf("%s: %c\n", nodeNames[node->nodeKind], node->val);
   	else if (node->nodeKind == 28)
      		printf("%s: %s\n", nodeNames[node->nodeKind], symbolTable[node->val]->string);
   	else if (node->nodeKind == 23 || node->nodeKind == 21 || node->nodeKind == 19)
      		printf("%s :%s\n", nodeNames[node->nodeKind], opNames[node->val]);


   	else//all else
      		printf("%s\n", nodeNames[node->nodeKind]);
  	int i, j;

  	for (i = 0; i < node->numChildren; i++)  {
    		for (j = 0; j < nestLevel; j++) 
      			printf("\t");
    		printAst(getChild(node, i), nestLevel + 1);
  	}
  }
  else {
        printf("node is null! @nestLevel: %i\n", nestLevel);
  }


}