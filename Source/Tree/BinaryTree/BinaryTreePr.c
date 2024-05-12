#include <stdio.h>
#include <stlib.h>
#include "BinaryTree.h"

/*** BTreeNode Operation ****/
BTreeNode * MakeBTreeNode(void){
	BTreeNode * newTreeNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newTreeNode->left = NULL;
	newTreeNode->right = NULL;
	return newTreeNode;
	
}
BTData GetData(BTreeNode * bt){
	return bt->data;
}
void SetData(BTreeNode * bt, BTData data){
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt){
	return bt->left;
}
BTreeNode * GetRightSubTree(BTreeNode * bt){
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub){
	if(main->left != NULL){
		free(main->left);		
	}
	main->left = sub;
}
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub){
	if(main->right != NULL){
		free(main->right);		
	}
	main->right = sub;
}