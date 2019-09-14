#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	node* prev;
	int value;
	node* next;
};

node* head;
node* point;

void put(int x){
	node* temp = (node*)malloc(sizeof(node*));
	temp->prev = head->prev;
	temp->prev->next = temp;
	temp->next = head;
	head->prev = temp;
	temp->value = x;
}

int pop(int M){
	for(int i=1; i<M; i++){
		point = point->next;
	}
	node* temp = point;
	int value = point->value;
	point = point->next;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
	return value;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	head = (node*)malloc(sizeof(node*));
	head->prev = head;
	head->next = head;
	head->value = 1;
	point = (node*)malloc(sizeof(node*));
	point = head;
	for(int i=2; i<=N; i++){
		put(i);
	}
	printf("<");
	for(int i=1; i<=N; i++){
		printf("%d", pop(M));
		if(i!=N) printf(", ");
		else printf(">");
	}
}
