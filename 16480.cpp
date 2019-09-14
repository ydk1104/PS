#include<stdio.h>

int main(void){
	long long int R, r;
	scanf("%lld %lld", &R, &r);
	printf("%lld", R*(R-2*r));
}
