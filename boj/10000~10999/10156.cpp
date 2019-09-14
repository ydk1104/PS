#include<stdio.h>

int main(void){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int ans = a*b-c;
	ans<0 ? ans=0 : 0 ;
	printf("%d", ans);
}
