#include<stdio.h>

int main(void){
	char s[101];
	scanf("%s", &s);
	for(int i=0; s[i]; i++){
		if(s[i]>'Z') printf("%c",s[i]-32);
		else printf("%c",s[i]+32);
	}
}
