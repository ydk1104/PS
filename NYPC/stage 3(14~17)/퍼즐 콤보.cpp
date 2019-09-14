#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char color;
	node* next;
}node;

node* head;
char s[1000001];

void push(char color){
	node *temp = (node*)malloc(sizeof(node));
	temp->color = color;
	temp->next = NULL;
	node* i = head;
	while(i->next != NULL){
		i = i->next;
	}
	i->next = temp;
}

int check(node* temp){
	int row = 0;
	int color = temp->next->color;
	while(temp->next != NULL){
		if(color != temp->next->color) break;
		row++;
		temp = temp->next;
	}
	return row;
}

void pop(node *x, int row){
	for(int i=1; i<=row; i++){
		node *temp;
		temp = x->next;
		x->next = temp->next;
		free(temp);
	}
}

int main(void){
	head = (node*)calloc(sizeof(node), 1);
	int N;
	scanf("%d", &N);
	scanf("%s", &s);
	for(int i=0; i<N; i++){
		push(s[i]);
	}
	int combo = 0;
	for(int i=1; i<=N; i++){
		int flag = 0;
		node* temp = head;
		while(temp->next != NULL){
			int checktemp = check(temp);
			if(checktemp>=3){
				pop(temp, checktemp);
				flag = 1;
			}
			if(checktemp >= 1 && checktemp<= 2) temp=temp->next;
			if(checktemp == 2) temp=temp->next;
			if(temp == NULL) break;
		}
		if(flag == 0) break;
		combo++;
	}
	printf("%d\n", combo);
	if(head->next == NULL) printf("PERFECT!!!");
	while(head->next != NULL){
		printf("%c", head->next->color);
		head = head->next;
	}
}
