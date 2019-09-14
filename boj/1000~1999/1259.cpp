#include<stdio.h>

int main(void){
	char s[9]={1};
	while(1){
		scanf("%s",s);
		if(*s=='0') break;
		int i=0; while(s[i])i++;
		for(int j=0; j<i; j++) if(s[j]!=s[i-j-1]) goto v;
		printf("yes\n"); continue;
		v:
		printf("no\n");
	}
}
