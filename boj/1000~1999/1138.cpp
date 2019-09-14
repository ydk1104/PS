#include<stdio.h>
#include<stdlib.h>

struct node{
	node* next;
	int value;
};

node* head;

void push(int value, int cnt){
	node* i = head;
	while(cnt--) i=i->next;
	node* temp = (node*)malloc(sizeof(node));
	temp->next = i->next;
	i->next = temp;
	temp->value = value;
}

int main(void){
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	int N, a[11];
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &a[i]);
	for(int i=N; i>0; i--) push(i, a[i]);
	for(node* i=head; i->next!=NULL; i=i->next) printf("%d ", i->next->value);
}
