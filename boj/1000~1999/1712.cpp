#include<stdio.h>

int main(void){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(b>=c) printf("-1");
	else printf("%d", 1+a/(c-b));
}
