#ifndef dk_tool
#define dk_tool
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Point description
typedef struct aNode
{
	char value;
	struct aNode *next;
}Node;
// Init interface
Node* add(Node *theNode, char val);
void del(Node *theNode);
void print(Node *theNode);
Node *load_from_file(char *path);

#endif
