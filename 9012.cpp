#include<stdio.h>

int stack[100];
int end;

void push(void){
	end++;
}

int pop(void){
	if(end==0){
		return -1;
	}
	end--;
	return 0;
}

int main(void){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		char s[50];
		scanf("%s", &s);
		int i;
		for(i=0; s[i]!='\0'; i++){
			if(s[i] == '('){
				push();
			}
			else{
				int a = pop(); 
				if(a==-1){
					printf("NO\n");
					break;
				}
			}
		}
		if(s[i]=='\0'){
			if(pop() == -1){
				printf("YES\n");
			}
			else{
				printf("NO\n");
				while(pop()!=-1){
				}
			}
			
		}
	}
}
