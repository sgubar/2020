#ifndef DK_TOOL_H_INCLUDED
#define DK_TOOL_H_INCLUDED

typedef struct __node doubleNode;

struct __node
{
    double value;
    doubleNode *leftChild;
    doubleNode *rightChild;
};

typedef struct __tree
{
    doubleNode *root;
    double count;
}doubleTree;

doubleTree *createDoubleTree();
void deleteDoubleTree(doubleTree *aTree);
void printTree(doubleNode *aRoot);

void insertDoubleValueToTree(doubleTree *aTree, double aValue);
double deleteValueFromTree(doubleTree *aTree, double aValue);

doubleNode *findNodeWithValue(doubleTree *aTree ,double aValue);

#endif // DK_TOOL_H_INCLUDED
