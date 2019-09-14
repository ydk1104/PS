#include<stdio.h>

int main(void){
	char s[100001];
	scanf("%s",&s);
	for(int i=0; s[i]; i++) printf("%d\n",i);
}
