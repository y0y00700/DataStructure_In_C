#include <stdio.h>
#include <stlib.h>
#include "BinaryTree2.h"

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

typedef void VisitFuncPtr(BTData data); // Function Pointer

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action){
	if(bt!=NULL){
		action(bt->data);
		PreorderTraverse(bt->left,action);
		PreorderTraverse(bt->right,action);
	}
	return;
}

void InorderTraverse(BTreeNode * bt, VisitFuncPtr action){
	if(bt!=NULL){
		InorderTraverse(bt->left,action);
		action(bt->data);
		InorderTraverse(bt->right,action);
	}	
	return;
}

void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action){
	if(bt!=NULL){
		PostorderTraverse(bt->left,action);
		PostorderTraverse(bt->right,action);
		action(bt->data);
	}
	return;
}