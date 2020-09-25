#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data{
	int number;
	struct Data *left;
	struct Data *right;
}*root;

struct Data *add(struct Data *node, int n){
	if(node == NULL){
		node = (struct Data*)malloc(sizeof(struct Data));
		node->number = n;
		node->left = node->right = NULL;
	}else{
		if(n < node->number){
			node->left = add(node->left,n);
		}else if(n > node->number){
			node->right = add(node->right, n);
		}
	}
	return  node;
}

void preorder(struct Data *curr){
	if(curr != NULL){
		printf("%d ", curr->number);
		preorder(curr->left);
		preorder(curr->right);
	}
}

void inorder(struct Data *curr){
	if(curr != NULL){
		inorder(curr->left);
		printf("%d ",curr->number);
		inorder (curr->right);
	}
}

void postorder(struct Data *curr){
	if(curr != NULL){
		postorder(curr->left);
		postorder(curr->right);
		printf("%d ",curr->number);
	}
}

struct Data *findMaxNode(struct Data *curr){
	while(curr->right !=NULL){
		curr= curr->right;
	}
	return curr;
}

struct Data *del(struct Data *node,int n){
	if(node==NULL){
		printf("Node is empty\n");
		return NULL;
	}else{
		if(n < node->number){
			node->left = del(node->left,n);
		}else if(n > node->number){
			node->right = del(node->right,n);
		}
		else{
			if(node->left == NULL && node->right == NULL){
				free(node);
				node=NULL;
			}else if(node->left ==NULL){
				struct Data *temp = node;
				node = node->right;
				free(temp);
			}else if(node->right == NULL){
				struct Data *temp = node;
				node = node->left;
				free(temp);
				temp = NULL;
			}else{
				struct Data *temp = findMaxNode(node->left);
				node->number= temp->number;
				node->left = del(node->left, temp->number);
			}
		}
		return node;
	} 
}

struct Data *popAll(struct Data *curr){
	if(curr != NULL){
		popAll(curr->left);
		popAll(curr->right);
		free(curr);
	}
	return NULL;
}

int main(){
//	double linked list
//	single linked list
	
	root = add(root, 10);
	root = add(root, 5);
	root = add(root, 3);
	root = add(root, 15);
	root = add(root, 1);
	root = add(root, 7);
	
	root = popAll(root);
	
	printf("PREORDER :\n");
	preorder(root);
	printf("\nINORDER :\n");
	inorder(root);
	printf("\nPOSTORDER :\n");
	postorder(root);
	
	
	return 0;
}
