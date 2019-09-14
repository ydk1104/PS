#include<stdio.h>

int main(void){
	long long a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	if(a>b+1) a=b+1;
	if(b>a+1) b=a+1;
	printf("%lld",a+b+2*c);
}
