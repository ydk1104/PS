#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	node* next;
};

node* head;

void put(int x){
	node* temp = (node*)malloc(sizeof(node*));
	node* i;
	i = head;
	while(i->next != NULL){
		i = i->next;
	}
	i->next = temp;
	temp->next = NULL;
	temp->value = x;
}

int pop(int x){
	node* i;
	i = head;
	while(i->next->next != NULL){
		i = i->next;
	}
	node* temp = i->next;
	i->next = NULL;
	int value = temp->value;
	free(temp);
	return value;
}

int main(void){
	head = (node*)malloc(sizeof(node*));
	head->next = NULL;
	for(int i=1; i<=10; i++){
		put(i);
	}
	for(int i=1; i<=10; i++){
		printf("%d\n", pop(i));
	}
}
