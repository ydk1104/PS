#include<stdio.h>

char s[51];
char left;
int ans;

int main(void){
	scanf("%s", &s);
	for(int i=0; s[i]!=0; i++){
		if(s[i] != left) ans+=5;
		ans+=5;
		left = s[i];
	}
	printf("%d", ans);
}
