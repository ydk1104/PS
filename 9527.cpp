#include<stdio.h>

long long ans(long long x){
	if(x==0) return 0;
	long long temp = 1, cnt = 0;
	while(temp<<1 <= x) temp=temp<<1, cnt++;
	return 1 + x^temp + ans(x^temp) + (1LL<<cnt-1)*cnt;
}

int main(void){
	long long a,b;
	scanf("%lld %lld", &a, &b);
//	for(int i=a; i<=b; i++) printf("%lld\n", ans(i));
	printf("%lld", ans(b)-ans(a-1));
}
