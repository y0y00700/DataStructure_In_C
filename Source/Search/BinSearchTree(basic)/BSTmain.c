#include <stdio.h>
#include <stdlib.h>

typedef char data;
typedef struct _Node{
	char key;
	struct _Node* left;
	struct _Node* right;
}Node;

Node* searchBST(Node* root, char x){
	Node* p = root;
	while(p!=NULL){
		if(p->key == x)
			return p;
		else if(p->key < x)
			p = p->right;
		else 
			p = p->left;
	}
	return NULL;
}

Node* insertBST(Node* root, char x){
	Node* p = root;
	Node* parent = NULL; // 루트가 비어있는 경우 노드를 무조건 삽입해야 하므로 초기값은 NULL로 지정해준다. 
	// 탐색 (parent 변수가 추가됨) 
	while(p!=NULL){
		parent = p; 
		if(p->key == x){
			printf("same key exit!\n");
			return p;
		}
		else if(p->key < x)
			p = p->right;
		else 
			p = p->left;
	}
	
	// 새노드 할당
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->key = x;
	newNode->left = newNode->right = NULL;
	 
	 //parent의 자식으로 새노드 붙이기.
	if(parent!=NULL){
		if(parent->key < newNode->key)
			parent->right = newNode;
		else
			parent->left = newNode;
	}
	return newNode;
}


Node* deleteBST(Node* root, char x){
	Node* p = root;
	Node* parent = NULL; // 루트가 비어있는 경우 노드를 무조건 삽입해야 하므로 초기값은 NULL로 지정해준다. 
	// 탐색 (parent 변수가 추가됨) 
	while((p!=NULL)&&(p->key !=x)){
		parent = p; 
		if(p->key < x)
			p = p->right;
		else 
			p = p->left;
	}
	if(p==NULL){
		printf("찾는 노드가 없습니다.\n");
		return root;
	}
	
	if(p->left==NULL&&p->right == NULL){ // 차수가 0인 경우 
		if(parent==NULL)
			root = NULL;
		else{
			if(parent->left == p)
				parent->left = NULL;
			else 
				parent->right = NULL;
		}
	}else if(p->left==NULL||p->right ==NULL){ // 차수가 1 인경우
		Node* child =(p->left !=NULL) ? p->left : p->right;
		if(parent == NULL)
			root = child;
		else{
			if(parent->left == p)
				parent->left = child;
			else
				parent->right = child;
		}
	}else{ // 차수가 2 인경우 (우측트리의 왼쪽자식이 없는 노드가 최종 successor)
		Node* succ_parent = p;
		Node* succ = p->right;
		while (succ->left !=NULL){
			succ_parent = succ;
			succ = succ->left;
		}
		p->key = succ->key; // root 에 succ 를 치환
		if(succ_parent->left == succ)
			succ_parent->left = succ->right;
		else 
			succ_parent->right = succ->right;
		p = succ;
	}
	
	free(p); 
	return root;
}

void Inorder(Node* root){// Inorder Traverse
	if(root ==NULL)
		return;
	Inorder(root->left);
	printf("%c",root->key);
	Inorder(root->right);
}
int main(void) {
	Node* root = insertBST(NULL,'D');
	insertBST(root,'I');
	insertBST(root,'F');
	insertBST(root,'A');
	insertBST(root,'G');
	insertBST(root,'C');
	Inorder(root); printf("\n");
	
	root = deleteBST(root,'C');
	Inorder(root); print("\n");
	return 0;
}