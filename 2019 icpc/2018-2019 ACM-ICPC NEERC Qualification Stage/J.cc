#include<stdio.h>
#include<algorithm>
 
long long gcd(long long a, long long b){return b?gcd(b,a%b):a;}
 
int main(void){
	long long a,b,c,d;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	long long e = gcd(c,d);
	printf("%lld\n", std::min(a/(c/e), b/(d/e)));
}
