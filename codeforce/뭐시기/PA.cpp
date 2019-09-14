#include<stdio.h>

char s[51];
int l, r;

int main(void){
	scanf("%s", &s);
	for(int i=0; s[i]; i++){
		if(s[i] == 'a') l++;
		else r++;
	}
	if(l<=r) printf("%d", 2*l-1);
	else printf("%d", l+r);
}
