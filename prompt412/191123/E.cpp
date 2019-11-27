#include<stdio.h>
#include<algorithm>

int main(void){
	long long N, a,b,c;
	scanf("%lld %lld %lld %lld", &N, &a, &b, &c);
	long long ans = N/a;
	if(N>=b) ans = std::max(ans, (N-b)/(b-c)+1+((N-b)%(b-c)+c)/a);
	printf("%lld", ans);
}
