#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int value;
	node* next;
}node;

void push(node* head, int value){
	node* temp = (node*)malloc(sizeof(node));
	temp->value = value;
	temp->next = head->next;
	head->next = temp;
}

int top(node* head){
	if(head->next == NULL) return 0;
	return head->next->value;
}

int pop(node* head){
	if(head->next == NULL) return 0;
	node* temp = head->next;
	head->next = temp->next;
	int value = temp->value;
	free(temp);
	return value;
}

int priority(char x){
	if(x=='*' || x=='/') return 2;
	if(x=='+' || x=='-') return 1;
	if(x >= 'A' && x <= 'Z') return 3;
	if(x=='(') return 0;
	if(x==')') return -1;
	if(!x) return -2;
	printf("Error : %c\n", x);
	return -5;
}

int compare(char x, char y){
	return priority(x) - priority(y);
}

void ConvertExp(char exp[]){
	node* head = (node*)calloc(sizeof(node), 1);
	
	int size = 0;
	
	for(int i=0; exp[i]; i++){
		if(top(head) == 0){
			push(head, exp[i]);
			continue;
		}
		if(exp[i] == '('){
			push(head, exp[i]);
			continue;
		}
		if(exp[i] == ')'){
			while(exp[size-1] != '(') exp[size++] = pop(head);
			size--;
			continue;
		}
		
		while(compare(top(head), exp[i]) >= 0)
			if(top(head) != '(' && top(head) != ')') exp[size++] = pop(head);
			else pop(head);
		push(head, exp[i]);
	}
	while(top(head))
		if(top(head) != '(' && top(head) != ')') exp[size++] = pop(head);
		else pop(head);
	exp[size] = 0;

	free(head);
}

int main(void){
	char s[101];
	scanf("%s", &s);
	ConvertExp(s);
	printf("%s", s);
}
