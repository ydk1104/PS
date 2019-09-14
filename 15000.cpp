#include<stdio.h>

int main(void){
	char s[1000001];
	scanf("%s", &s);
	for(int i=0; s[i]; i++){
		s[i]-=32;
	}
	printf("%s",s);
}
