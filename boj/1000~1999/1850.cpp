#include<stdio.h>

long long int gcd(long long int a, long long int b){
	if(a==0) return b;
	if(b==0) return a;
	if(a>b) return gcd(a%b, b);
	return gcd(a, b%a);
}

int main(void){
	long long int A, B;
	scanf("%lld %lld", &A, &B);
	for(int i=gcd(A,B); i>0; i--){
		printf("1");
	}
}
