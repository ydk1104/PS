#include<stdio.h>
#include<stdlib.h>

class node{
	public:
	node* pa;
	node* next;
	node* fi;
	int num;
};

void push(int x){
	
}

node* find(node *x){
	if(x->pa == x) return x;
	return x->pa = find(x->pa);
}

node* head;

void merge(int x, int y){
	node* px = find(head+x);
	node* py = find(head+y);
	py->pa = px;
	px->fi->next = py;
	px->fi = py->fi;
}

int main(void){
	int N;
	scanf("%d", &N);
	head = (node*)calloc(sizeof(node), N+1);
	for(int i=1; i<=N; i++){
		node* temp = head+i;
		temp->num = i;
		temp->pa = temp;
		temp->fi = temp;
		temp->next = NULL;
	}
	for(int i=1; i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	node* pa = find(head+1);
	printf("%d ", pa->num);
	for(node* i=pa; i->next!=NULL; i=i->next){
		printf("%d ", i->next->num);
	}
}
