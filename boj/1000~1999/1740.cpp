#include<stdio.h>

int main(void){
	long long N;
	scanf("%lld", &N);
	long long ans=0, now=1;
	while(N){
		if(N%2) ans+=now;
		N/=2;
		now*=3;
	}
	printf("%lld", ans);
}
