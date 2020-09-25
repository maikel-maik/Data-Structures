#include<stdio.h>
#include<stdlib.h>

struct Data{
	int value;
	struct Data *next;
}*head,  *tail;

void pushHead(int val){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	(*node).value = val;
	//node->value = val;
	node->next = NULL;
	
	if(head == NULL){
		head = tail = node;	
	}
	else{
		node->next = head;
		head = node;
	}
}

void pushTail(int val){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	(*node).value = val;
	//node->value = val;
	node->next = NULL;
	
	if(tail == NULL){
		head = tail = node;	
	}
	else{
		tail->next = node;
		tail = node;
	}
}

void printAll(){
	struct Data *curr = head;
	while(curr != NULL){
		printf("%d ",curr->value);
		curr = curr->next;
	}
}

void pushMid(int val)
{
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	node->value=val;
	node->next=NULL;
	
	if(head==NULL){
		head = tail = node;
	}
	else if(val <= head->value){
		node->next = head;
		head = node;
	}
	else if(val >= tail->value){
		tail->next=node;
		tail=node;
	}
	else{
		struct Data *curr = head;
		while(curr->next->value < val){
			curr = curr->next;
		}
		
		node->next=curr->next;
		curr->next=node;
	}
}

void popHead(){
	if(head != NULL){
		if(head == tail){
			free(head);
			head = tail = NULL;
		}else{
			struct Data *node = head;
			head = head->next;
			free(node);
			node = NULL;
		}
	}
}

void popTail(){
	if(head != NULL){
		if(head == tail){
			free(head);
			head= tail= NULL;
		}
		else{
			struct Data *node = head;
			while(node->next != tail){
				node=node->next;
			}
//			free(tail);
//			tail=node;
//			node->next= NULL;

			tail = node;
			free(tail->next);
			tail->next=NULL;
		}
	}
}

void popMid(int val){
	if(head!=NULL){
		if(head==tail){
			
			free(head);
			head=tail=NULL;
		}
		else if(val == head->value)
		{
			
			struct Data *node = head;
			head = head->next;
			free(node);
			node = NULL;
		}
		else if(val == tail->value)
		{
			
			struct Data *node = head;
			while(node->next != tail)
			{
				node= node->next;
			}
			tail=node;
			free(tail->next);
			tail->next=NULL;
		}
		else{
			
			struct Data *node = head;
			while(node->next->value < val && node->next != tail)
			{
				node=node->next;
			}
			if(node->next->value == val)
			{
				struct Data *temp = node->next;
				node->next = temp->next;
				free(temp);
				temp = NULL;
			}else{
				printf("Data not found\n");
			}
			
			
		}
	}
}

popAll(){
	while(head!=NULL)
	{
		popHead();
	}
}


int main()
{
//	pushTail(50);
//	pushTail(75);
//	pushTail(20);
//	pushTail(30);
//		
//	printAll();

	printf("Result\n");
	
	pushMid(50); 
	pushMid(20);
	pushMid(30);
	pushMid(10);
	pushMid(40);
	
	popMid(20);
	printAll();
	puts("");
		
	/*
	int *p = (int*)malloc(sizeof(int));
	*p = 15;
	printf("%d\n",*p);
	free(p);
	printf("%d\n",*p);   
	malloc pake stdlib
	*/
	
	
		
	
	return 0;
}
