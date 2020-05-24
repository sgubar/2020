#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

///////////////////////////////////////// Створення дерева ///////////////////////////////////////////////

Tree* createTree()
{
	Node* rootNode = (Node*)malloc(sizeof(Node));
	scanf("%lf", &rootNode->field);
	rootNode->leftChild = NULL;
	rootNode->rightChild = NULL;
	rootNode->parent = NULL;
	Tree* theTree = (Tree*)malloc(sizeof(Tree));
	theTree->root = rootNode; 

	double val;
	scanf("%lf", &val);
	char c;
	scanf("%c", &c);
	while(c != '\\'){
		searchPlace(rootNode, val);			// додавання елементу в дерево
		scanf("%lf", &val);
		scanf("%c", &c);
	}
	
	return theTree;
}

////////////////////////////////////// Додавання ноди //////////////////////////////////////////////////

void createNode(Node* node, double val, char* c)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->field = val;
	new_node->leftChild = NULL;
	new_node->rightChild = NULL;
	new_node->parent = node;
	if(c == "r")node->rightChild = new_node;
	else if(c == "l")node->leftChild = new_node;
}



void searchPlace(Node* node, double val)
{
	if(val > node->field){
		if(node->rightChild) searchPlace(node->rightChild, val);
		else createNode(node, val, "r");
	}else{
		if(node->leftChild) searchPlace(node->leftChild, val);
		else createNode(node, val, "l");
	}
}

//////////////////////////////////////////////// Друк дерева зворотнім обходом //////////////////////////////////////////

void postOrderTravers(Node* root) 
{
    if(root) {
        postOrderTravers(root->leftChild);
        postOrderTravers(root->rightChild);
        printf("%lf ", root->field);
    }
}

/////////////////////////////////// Пошук Ноди ///////////////////////////////////////////////////

Node* SearchNode(Node* node, double val)
{
	while(node){
		if(val > node->field)node = node->rightChild;
		else if(val < node->field)node = node->leftChild;
		else return node;
	} 
	return NULL;
}

/////////////////////////////////// Видалення ноди ////////////////////////////////////////////

void rmNode(Node* tmp, double val)
{
	tmp = SearchNode(tmp, val);
    if(tmp->leftChild == NULL && tmp->rightChild == NULL){										// лист
    	if(tmp->field > tmp->parent->field) tmp->parent->rightChild = NULL;
    	else tmp->parent->leftChild = NULL;
    }else if(tmp->leftChild == NULL && tmp->field > tmp->parent->field) tmp->parent->rightChild = tmp->rightChild;			// 1 наследник правый, tmp правый
    else if(tmp->leftChild == NULL && tmp->field < tmp->parent->field) tmp->parent->leftChild = tmp->rightChild;			// 1 наследник правый, tmp левый
    else if(tmp->rightChild == NULL && tmp->field > tmp->parent->field) tmp->parent->rightChild = tmp->leftChild;			// 1 наследник левый, tmp правый
    else if(tmp->rightChild == NULL && tmp->field < tmp->parent->field) tmp->parent->leftChild = tmp->leftChild;			// 1 наследник	левый, tmp левый						
    else if(tmp->leftChild && tmp->rightChild){								// 2 наследника
    	Node* node = tmp->leftChild;
    	while(node->rightChild)node = node->rightChild;
    	if(tmp->field > tmp->parent->field) tmp->parent->rightChild = node;
    	else  tmp->parent->leftChild = node;
    	node->rightChild = tmp->rightChild;
    }											
    free(tmp);
}

//////////////////////////////// Видалення дерева ///////////////////////////////////////////////////

void ClearNode(Node* node)
{
    if(node != NULL){
        if(node->leftChild != NULL)
            ClearNode(node->leftChild);
        if(node->rightChild != NULL)
            ClearNode(node->rightChild);
        free(node);
    }
}