#include<stdio.h>

typedef struct stack{
	char s[50];
	int top;
}st;

st stack;
char s[31];
int value = 1;
int ans = 0;

void push(char x){
	stack.s[stack.top++] = x;
	if(x == '(') value *= 2;
	else value *= 3;
}

char pop(){
	char temp = stack.s[--stack.top];
	if(temp == '(') value /= 2;
	else value /= 3;
	return temp;
}

int main(void){
	scanf("%s", &s);
	for(int i=0; s[i]!='\0'; i++){
		if(s[i] == '(') push(s[i]);
		if(s[i] == '[') push(s[i]);
		if(s[i] == ')'){
			if(s[i-1] == '(') ans += value;
			char temp = pop();
			if(temp != '('){
				printf("0");
				return 0;
			}
		}
		if(s[i] == ']'){
			if(s[i-1] == '[') ans += value;
			char temp = pop();
			if(temp != '['){
				printf("0");
				return 0;
			}
		}
	}
	if(stack.top == 0) printf("%d", ans);
	else printf("0");
}
