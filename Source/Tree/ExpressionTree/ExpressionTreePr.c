#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree2.h"

// 후위 표기법의 수식을 인자로 받아서 수식 트리를 구성하고 루트 노드의 주소값 반환
BTreeNode * MakeExpTree(char exp[]){
	int i;
	Stack st;
	BTreeNode * bt;
	int expLen = strlen(ext);	
	for(i=0;i<expLen;i++){
		bt = MakeBTreeNode();
		if(exp[i].isDigit){
			SetData(bt,exp[i]-'0');
		}else{
			MakeLeftSubTree(bt, SPop(&st));
			MakeRightSubTree(bt, SPop(&st));
			SetData(bt,exp[i]);
		}
		SPush(&st,bt);
	}
	return SPop(&st);
}

int EvaluateExpTree(BTreeNode * bt){
	int op1,op2;
//	op1 = GetData(GetLeftSubTree(bt));	
//	op2 = GetData(GetRightSubTree(bt));
	
	if(GetLeftSubTree(bt)==NULL && GetRightSubTree(bt)==NULL)
		return GetData(bt);
		
	op1 = EvaluateExpTree(GetLeftSubTree(bt));	
	op2 = EvaluateExpTree(GetRightSubTree(bt));
		
	switch(GetData(bt)){
		case '+':
			return op1+op2;		
		case '-':
			return op1-op2;
		case '*':
			return op1*op2;
		case '/':
			return op1/op2;						
	}
	return 0;
}

// Data output Function (Character or Integer)
void ShowNodeData(int data)
{
	if(0<=data && data<=9)
		printf("%d ", data);
	else
		printf("%c ", data);
}
// Expression Print (Pre,In,Post)
void ShowPrefixTypeExp(BTreeNode * bt){
	PreorderTraverse(bt,ShowNodeData);
}
void ShowInfixTypeExp(BTreeNode * bt){
	InorderTraverse(bt,ShowNodeData);
}
void ShowPostfixTypeExp(BTreeNode * bt){
	PostorderTraverse(bt,ShowNodeData);
}

