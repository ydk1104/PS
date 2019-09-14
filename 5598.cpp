#include<stdio.h>

int main(void){
	char s[1001];
	scanf("%s", &s);
	for(int i=0;s[i];i++){
		s[i]-=3;
		if(s[i]<'A') s[i]+=26;
		printf("%c",s[i]);
	}
}
