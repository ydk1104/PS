#include<stdio.h>

long long gcd(long long a, long long b){
	return b ? gcd(b,a%b) : a;
}

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		long long a, b;
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", a*b/gcd(a,b));
	}
}
