//
//  Functions.c
//  Laboratory Work 5
//
//  Created by Nazar Diadiun on 28.05.2020.
//  Copyright © 2020 Nazar Diadiun. All rights reserved.
//

#include "Functions.h"

//This function would determine the position as per value of node to be added and new node would be added into binary tree
 void insert(node ** tree, float val)
 {
     node *temp = NULL;
     //Check first if tree is empty, then insert node as root.
     if(!(*tree))
     {
         temp = (node *)malloc(sizeof(node));
         temp->left = temp->right = NULL;
         temp->data = val;
         *tree = temp;
         return;
     }

     //Check if node value to be inserted is lesser than root node value, then
     if(val < (*tree)->data)
         insert(&(*tree)->left, val); //Call insert() function recursively while there is non-NULL left node
     //When reached to leftmost node as NULL, insert new node.
     
     //Check if node value to be inserted is greater than root node value, then
     else if(val > (*tree)->data)
         insert(&(*tree)->right, val); //Call insert() function recursively while there is non-NULL right node
     //When reached to rightmost node as NULL, insert new node.

}

//This search function would search for value of node whether node of same value already exists in binary tree or not. If it is found, then searched node is returned otherwise NULL (i.e. no node) is returned.
node* search(node ** tree, float val) {
    //Check first if tree is empty, then return NULL.
 if(!(*tree)) {
   return NULL;
  }
    //Check if node value to be searched is equal to root node value, then return node
 if(val == (*tree)->data) {
   return *tree;
     }
     //Check if node value to be searched is lesser than root node value, then call search() function recursively with left node
   else if(val < (*tree)->data) {
    search(&((*tree)->left), val);
  }
    //Check if node value to be searched is greater than root node value, then call search() function recursively with right node
   else if(val > (*tree)->data){
    search(&((*tree)->right), val);
  }
    //Repeat step 2, 3, 4 for each recursion call of this search function until node to be searched is found.
    
    return 0;
 }


void deltree(node * tree) {
    //Check first if root node is non-NULL, then
 if (tree) {
   deltree(tree->left);//Call deltree() function recursively while there is non-NULL left node
   deltree(tree->right);//Call deltree() function recursively while there is non-NULL right node
   free(tree);//Delete the node.
  }
 }

 void print_inorder(node * tree) {
 if (tree) {
 print_inorder(tree->left);//Call print_inorder() function recursively while there is non-NULL left node
 printf("%f\n",tree->data);//Display value of root node.
 print_inorder(tree->right);//Call print_inorder() function recursively while there is non-NULL right node
 }
 }
