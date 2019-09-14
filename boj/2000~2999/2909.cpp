#include<stdio.h>

int main(void){
	int a, b, c=1;
	scanf("%d %d", &a, &b);
	while(b) c*=10, b--;
	if(a%c >= c/2) printf("%d", (a/c+1)*c);
	else printf("%d", a/c*c);
}
