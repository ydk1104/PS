#include<stdio.h>
#define min(a,b) (a<b)&&(a!=-1) ? a : b

int main(void){
	char s[101];
	int a[26];
	for(int i=0; i<=25; i++){
		a[i] = -1;
	}
	scanf("%s", s);
	for(int i=0; s[i]!='\0'; i++){
		a[s[i]-'a'] = min(a[s[i]-'a'], i);
	}
	for(int i=0; i<=25; i++){
		printf("%d ",a[i]);
	}
}
