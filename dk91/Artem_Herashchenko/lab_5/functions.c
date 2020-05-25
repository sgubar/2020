#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

Node *create_node(Node *root, int *val)              //створення кореня
{
	Node *thetree = malloc(sizeof(Node));
	if(thetree != NULL)
  	{
		thetree->value = val;
		thetree->left = NULL;
		thetree->right = NULL;
		thetree->root = root;
  	}
  	return thetree;
}

void add_node(Node **thetree, int *val)               //додавання елементів
{
	Node *tmp = NULL;
	if(*thetree == NULL)
	{
  	  *thetree = create_node(NULL, val);
  	  return;
	}
	tmp = *thetree;
		while(tmp)
		{
			if(val > tmp->value)
			{
				if(tmp->right)
				{
					tmp = tmp->right;
					continue;
				}else
				{
					tmp->right = create_node(tmp, val);
					return;
				}
			}else if(val < tmp->value)
			{
				if(tmp->left)
				{
					tmp = tmp->left;
					continue;
				}else
				{
					tmp->left = create_node(tmp, val);
					return;
				}
			}else
			{
				return;
			}
		}
}

//=======================================ФУНКЦІЇ ДЛЯ ВИДАЛЕННЯ=================================================
void delete_target(Node *target)                              //пошук вузла для видалення
 {
    if (target->left && target->right)
	{
        Node *max = find_max_min(target->left, 1);
        target->value = max->value;
        delete_target(max);
        return;
    } else if(target->left)
	{
        if(target == target->root->left)
		{
            target->root->left = target->left;
        } else
		{
            target->root->right = target->left;
        }
    } else if(target->right)
	{
        if (target == target->root->right)
		{
            target->root->right = target->right;
        } else
		{
            target->root->left = target->right;
        }
    } else
	{
        if(target == target->root->left)
		{
            target->root->left = NULL;
        } else {
            target->root->right = NULL;
        }
    }
    free(target);
}

Node *get_node_by_value(Node *root, int val)       //отримання значення вузла
{
    while (root)
	{
        if (root->value > val)
		{
            root = root->left;
            continue;
        } else if(root->value < val)
		{
            root = root->right;
            continue;
        } else
		{
            return root;
        }
    }
    return NULL;
}

Node *find_max_min(Node *root, int val)          //пошук max min елемента
{
	if(root != NULL)
	{
		Node *thenode = root;
		if(val == 0)
	 	{
		while(thenode->left)
			thenode = thenode->left;
		return thenode;
	 	}else if(val == 1)
	 	{
		while(thenode->right)
			thenode = thenode->right;
		return thenode;
 		}
	}
}

void delete_node(Node *root, int val)                //видалення елементу
{
    Node *target = get_node_by_value(root, val);
    delete_target(target);
}
//===============================================================================================================
int search(Node *thetree, int val)                  //пошук елементу
{
    while (thetree)
	{
        if (thetree->value > val)
		{
            thetree = thetree->left;
            continue;
        } else if(thetree->value < val)
		{
            thetree = thetree->right;
            continue;
        } else
		{
            return 1;
        }
    }
    return 0;
}

void tree_print(Node *thetree)                               //друк зворотнім обходом
{

		if(thetree)
		{
		tree_print(thetree->left);
		tree_print(thetree->right);
		printf("%d ", thetree->value);
		}
}

void tree_free(Node *thetree)                          //видалення дерева
{
		if(thetree)
		{
		 tree_free(thetree->left);
		 tree_free(thetree->right);
		 free(thetree);
		}
}
