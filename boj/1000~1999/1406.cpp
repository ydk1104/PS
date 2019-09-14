#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	node* left;
	char value;
	node* right;
}next;

char s[100001];
node* head;
node* tail;
node* point;

void push(char x){
	node* temp = (node*)malloc(sizeof(node*));
	temp->right = point;
	temp->left = point->left;
	point->left->right = temp;
	temp->value = x;
	point->left = temp;
}

void pop(){
	if(point->left == head) return;
	node* temp = point->left;
	temp->left->right = temp->right;
	temp->right->left = temp->left;
	free(temp);
}

int main(void){
	head = (node*)malloc(sizeof(node*));
	point = (node*)malloc(sizeof(node*));
	tail = (node*)malloc(sizeof(node*));
	point = tail;
	point->left = head;
	head->right = point;
	scanf("%s", &s);
	for(int i=0; s[i]!='\0'; i++){
		push(s[i]);
	}
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		getchar();
		char temp;
		scanf("%c", &temp);
		if(temp == 'L'){
			if(point->left != head){
				point=point->left;
			}
		}
		if(temp=='D'){
			if(point != tail){
				point=point->right;
			}
		}
		if(temp=='B'){
			pop();
		}
		if(temp=='P'){
			getchar();
			char x;
			scanf("%c", &x);
			push(x);
		}
	}
	for(head=head->right; head!=tail; head=head->right){
		printf("%c",head->value);
	}
}
