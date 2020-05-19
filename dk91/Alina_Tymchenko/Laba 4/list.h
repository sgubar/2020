#ifndef LIST_h
#define LIST_h


//structures
typedef struct tagNode Node;

struct tagNode
{
	int value;
	Node *nextNode;
	Node *prevNode;
};

typedef struct tagList
{
	Node *head;
	Node *tail;
	int count;
}List;


//node functions
	//creation & destruction
Node *createNode(int aValue);
void destroyNode(Node *aNode);

//list functions
	//creation & destruction
List *createList();
void destroyList(List *aList);

	//operations
Node *addNode(List *aList, Node *aNewNode);

	//misc actions
int countList(const List *aList);
Node *nodeAtIndex(const List *aList, int aIndex);
void swapNodes(List *aList, int aLeftIndex, int aRightIndex);

void printList();
#endif
