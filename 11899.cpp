#include<stdio.h>
#include<stack>

int ans, top;

void push(){
	top++;
}
void pop(){
	if(top) top--;
	else ans++;
}

int main(void){
	char s[51] = {0, };
	scanf("%s", &s);
	for(int i=0; s[i]; i++){
		if(s[i]=='(') push();
		else pop();
	}
	printf("%d", ans+top);
}
