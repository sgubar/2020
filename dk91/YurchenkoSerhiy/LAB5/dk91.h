#ifndef HW7_BINARE_TREE_H
#define HW7_BINARE_TREE_H
typedef struct __tagNode
{
    double value;
    struct __tagNode *leftChild;
    struct __tagNode *rightChild;
} DoubleNode;

typedef struct __tagTree
{
    DoubleNode *root;
    double count;
} DoubleTree;

void postOrder(DoubleNode *aNode);
void printTree (DoubleTree *aTree);

DoubleTree *createDoubleTree();
void destroyDoubleTree(DoubleTree *aTree);

void insertDoubleValueToTree(DoubleTree *aTree, double aValue);

DoubleNode *findNodeWithValue(DoubleTree *aTree, double aValue);

DoubleNode* FindMin(DoubleNode* aNode);
DoubleNode* deleteNodeWithElement(DoubleTree *aTree,DoubleNode* aNode, double aElement);

#endif
