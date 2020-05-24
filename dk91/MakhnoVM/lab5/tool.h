typedef struct __Node					// важдива структура для створення дерева
{
	double field;
	struct __Node *leftChild;
	struct __Node *rightChild;
	struct __Node *parent;
}Node;

typedef struct __Tree				// юзлес структура для створення дерева
{
	Node* root;
}Tree;

Tree* createTree();      // створення дерева

void createNode(Node* node, double val, char* c);      //створення ноди

void searchPlace(Node* node, double val);			// пошук місця для створення ноди

void postOrderTravers(Node* root);					// друк дерева зворотнім обходом

Node* SearchNode(Node* node, double val);			// пошук ноди

void rmNode(Node* root, double val);				// видалення ноди

void ClearNode(Node* node);					// видалення дерева