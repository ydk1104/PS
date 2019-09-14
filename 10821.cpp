#include<stdio.h>

int main(void){
	char s[101];
	scanf("%s", &s);
	int ans=1;
	for(int i=0; s[i]; i++) ans+=s[i]==',';
	printf("%d",ans);
}
