#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int num;
	node* next;
};

node* head;

void push(int num, int cnt){
	node* temp = (node*)malloc(sizeof(node*));
	temp->num = num;
	node* i = head;
	while(cnt>0){
		i = i->next;
		cnt--;
	}
	temp->next = i->next;
	i->next = temp;
}

int main(void){
	head = (node*)malloc(sizeof(node*));
	head->next = NULL;
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d", &x);
		push(i, x);
	}
	int ans[101];
	for(int i=1; i<=N; i++){
		ans[i]=head->next->num;
		head = head->next;
	}
	for(int i=N; i>0; i--){
		printf("%d ", ans[i]);
	}
}
