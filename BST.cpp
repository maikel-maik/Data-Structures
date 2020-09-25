#include<stdio.h>
#include<stdlib.h>

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
		if(n < node->number)
		{
			node->left = add(node->left,n);
		}else if(n > node->number){
			node->right = add(node->right, n);
		}
	}
	return node;
}

struct Data *findMaxNode(struct Data *curr) // predecessor
{
	while(curr->right != NULL){
		curr = curr->right;
	}
	return curr;
}

struct Data *del(struct Data *node, int n){
	if(node == NULL){
		printf("Node is empty\n");
		return NULL;
	}else{
		if(n < node->number){
			node->left = del(node->left, n);
		}else if(n > node->number){
			node->right = del(node->right, n);
		}else{
			if(node->left == NULL && node->right == NULL){
				free(node);
				node = NULL;
			}else if(node->left == NULL){
				struct Data *temp = node;
				node = node->right;
				free(temp);
				temp = NULL;
			}else if(node->right == NULL){
				struct Data *temp = node;
				node = node->left;
				free(temp);
				temp = NULL;
			}else{
				struct Data *temp = findMaxNode(node->left);
				//printf("nilai temp: %d\n", temp->number);
				node->number = temp->number;
				node->left = del(node->left, temp->number);
			}
		}
		return node;
	}
}

void preOrder(struct Data *curr){
	if(curr != NULL){
		printf("%d ", curr->number);
		preOrder(curr->left);
		preOrder(curr->right);
	}
}

void inOrder(struct Data *curr){
	if(curr != NULL){
		inOrder(curr->left);
		printf("%d ",curr->number);
		inOrder(curr->right);
	}
}

void postOrder(struct Data *curr){
	if(curr != NULL){
		postOrder(curr->left);
		postOrder(curr->right);
		printf("%d ",curr->number);
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
	
	root = add(root, 10);
	root = add(root, 5);
	root = add(root, 3);
	root = add(root, 15);
	root = add(root, 1);
	root = add(root, 7);
	
	root = popAll(root);
	
	/*root = del(root, 10);
	root = del(root, 5);
	root = del(root, 3);
	root = del(root, 15);
	root = del(root, 1);
	root = del(root, 7);*/
	
	printf("PREORDER:\n");
	preOrder(root);
	printf("\nINORDER:\n");
	inOrder(root);
	printf("\nPOSTORDER:\n");
	postOrder(root);
	
	printf("\n\n");
	
	return 0;
}
