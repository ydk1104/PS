#include<stdio.h>
#define abs(x) (((x)>0) ? (x) : (-(x)))

int main(void){
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", (a+b)*(abs(a-b)+1)/2);
}
