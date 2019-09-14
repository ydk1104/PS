#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int value;
	struct node *next;
}node;

node head;

void push(int N){
	node *temp = (node*)malloc(sizeof(node));
	node *p = &head;
	while(p->next != NULL){
		p = p->next;
	}
	p->next = temp;
	temp->value = N;
	temp->next = NULL;
}

int pop(){
	node *p = &head;
	if(p->next == NULL){
		return -1;
	}
	else{
		int temp = p->next->value;
		node* temp2 = p->next->next;
		free(p->next);
		p->next = temp2;
		return temp;
	}
}

int size(){
	int cnt = 0;
	node *p = &head;
	while(p->next != NULL){
		p = p->next;
		cnt++;
	}
	return cnt;
}

int empty(){
	node *p = &head;
	if(p->next == NULL){
		return 1;
	}
	else{
		return 0;	
	}
}

int front(){
	node *p = &head;
	if(p->next == NULL){
		return -1;
	}
	else{
		return p->next->value;
	}
}

int back(){
	node *p = &head;
	if(p->next == NULL){
		return -1;
	}
	else{
		while(p->next != NULL){
			p = p->next;
		}
		return p->value;
	}
}

int main(void){
	head.value = 0;
	head.next = NULL;
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		char s[10];
		scanf("%s", &s);
		if(strcmp(s, "push") == 0){
			int temp;
			scanf("%d", &temp);
			push(temp);
		}
		if(strcmp(s, "pop") == 0){
			printf("%d\n", pop());
		}
		if(strcmp(s, "size") == 0){
			printf("%d\n", size());
		}
		if(strcmp(s, "empty") == 0){
			printf("%d\n", empty());
		}
		if(strcmp(s, "front") == 0){
			printf("%d\n", front());
		}
		if(strcmp(s, "back") == 0){
			printf("%d\n", back());
		}
	}
}
