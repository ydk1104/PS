#include<stdio.h>

int main(void){
	char s[105];
	scanf("%s", &s);
	for(int i=0; s[i]!=0; i++){
		if(s[i]<= 'Z' && s[i] != '-') printf("%c", s[i]);
	}
}
