#include<stdio.h>

int main(void){
	char s[2][1001];
	gets(*s); gets(s[1]);
	int i=0;
	for(; s[0][i] && s[1][i]; i++);
	if(s[1][i]) printf("no");
	else printf("go");
}
