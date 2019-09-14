#include<stdio.h>

int main(void){
	char s[101];
	int abc[26] = {0, };
	scanf("%s", &s);
	for(int i=0; s[i]!='\0'; i++){
		abc[s[i]-'a']++;
	}
	for(int i=0; i<=25; i++){
		printf("%d ", abc[i]);
	}
}
