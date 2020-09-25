#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct Data{
	int value;
	char nama[100];
	struct Data *next;
	struct Data *prev;
}*head, *tail;

void pushHead(int x,char n[100]){
	struct Data *node =(struct Data*)malloc(sizeof(struct Data));
	node->value = x;
	strcpy(node->nama, n);
	node->next = node->prev = NULL;
	
	if(head == NULL)
		head = tail = node;
	else{
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void pushTail(int x,char n[100]){
	struct Data *node =(struct Data*)malloc(sizeof(struct Data));
	node->value = x;
	strcpy(node->nama, n);
	node->next = node->prev = NULL;
	
	if(head == NULL)
	{
		head = tail = node;
	}
	else{
		node->prev = tail;
		tail->next = node;
		tail=node;
		
	}
}

void pushMid(int x, char n[100]){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	node->value = x;
	strcpy(node->nama, n);
	node->next = NULL;
	node->prev = NULL;
	
	if(head==NULL){
		head = tail = node;
	}
	else if(node->value <= head->value){
		node->next = head;
		head->prev = node;
		head = node;
	}
	else if(node->value >= tail->value){
		tail->next = node;
		node->prev = tail;
		tail= node;
	}
	else{
		struct Data *curr =head;
		while(curr->next->value < node->value){
			curr = curr->next;
		}
			node->next = curr->next;
			node->next->prev = node;
			node->prev = curr->prev;
			curr->next = node;
		
	}
}

void popHead(){
	if(head == tail)
	{
		free(head);
		head = tail = NULL;
	}else{
		head= head->next;
		free(head->prev);
		head->prev = NULL;
	}
}

void popTail(){
	if(head == tail)
	{
		free(head);
		head= tail= NULL;
	}
	else{
		tail= tail->prev;
		free(tail->next);
		tail->next = NULL;
	}
}

void popMid(int x){
	if(head!=NULL){
		if(head == tail){
			if(head->value == x){
				free(head);
				head = tail = NULL;
			}
		}
		else if(head->value == x){
			head = head->next;
			free(head->prev);
			head->prev = NULL;
		}else if(tail->value == x){
			tail = tail->prev;
			free(tail->next);
			tail->next = NULL;
		}else{
			struct Data *curr = head;
			while(curr->value < x && curr != tail){
				curr= curr->next;
			}
			if(curr->value == x){
				curr->next->prev = curr->prev;
				curr->prev->next = curr->next;
				free(curr);
				curr=NULL;
			}else{
				printf("Not found.");
			}
		}
	}
}

void printAll(){
	struct Data *curr = head;
	while(curr != NULL){
		printf("[%d %s]",curr->value,curr->nama);
		curr=curr->next;
	}
}


int main(){
	
//	pushHead(5,"Andi");
//	pushHead(10,"Budi");
//	pushHead(15,"Caca");
//	pushHead(35,"Dodi");
//	pushHead(45,"Eric");
//	
//	pushTail(50,"Adam");
	
	pushMid(50,"Budi");
	pushMid(100,"Chris");
	pushMid(75,"Toni");
	pushMid(60,"Eugene");
	pushMid(15,"Marry");
	popMid(95);
	puts("");
	printAll();
	
	
	return 0;
}
