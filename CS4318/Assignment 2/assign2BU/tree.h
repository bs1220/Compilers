#ifndef TREE_H
#define TREE_H

#define MAXCHILDREN 12

typedef struct treenode tree; 



/* tree node - you may want to add more fields */
struct treenode {
  int nodeKind;
  int numChildren;
  int val;
  tree *parent;
  tree *children[MAXCHILDREN];
};

tree *maketree(int kind);
tree *maketreeWithVal(int kind, int val);


void addChild(tree *parent, tree *child);

void printAst(tree *root, int nestLevel);

/* tree manipulation macros */ 
/* if you are writing your compiler in C, you would want to have a large collection of these */

#define nextAvailChild(node) node->children[node->numChildren] 
#define getChild(node, index) node->children[index]
#endif