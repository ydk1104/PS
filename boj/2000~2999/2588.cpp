#include<stdio.h>

int main(void){
	int a, b;
	scanf("%d\n%d", &a, &b);
	int ans = a*b;
	for(;b>0;b/=10){
		printf("%d\n", a*(b%10));
	}
	printf("%d", ans);
}
