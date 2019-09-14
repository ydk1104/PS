#include<stdio.h>

int stack[10001];
int top;

void push(int x){
	stack[top++] = x;
}

void pop(){
	if(top>0) printf("%d\n", stack[--top]);
	else printf("-1\n");
}

void size(){
	printf("%d\n", top);
}

void empty(){
	printf("%d\n", (!top));
}

void Top(){
	if(top>0) printf("%d\n", stack[top-1]);
	else printf("-1\n");
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		char s[10];
		scanf("%s", &s);
		if(s[0] == 'p'){
			if(s[1] == 'u'){
				int x;
				scanf("%d", &x);
				push(x);
			}
			else{
				pop();
			}
		}
		else if(s[0] == 's'){
			size();
		}
		else if(s[0] == 'e'){
			empty();
		}
		else{
			Top();
		}
	}
}
