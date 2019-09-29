#include<stdio.h>

int main(void){
	long long x,N;
	long long ans=1, mod=1e9+7;
	scanf("%lld %lld", &x, &N);
	for(long long i=2; x!=1 || i*i<=x; i++){
		if(i*i>x) i=x;
		if(x%i) continue;
//		printf("%lld\n", i);
		while(x%i==0) x/=i;
		long long cnt=0;
		long long temp = N;
		while(temp) cnt+=temp/i, temp/=i;
		temp = i;
//		printf("%lld\n", cnt);
		while(cnt){
			if(cnt%2){
				ans *= temp;
				ans %= mod;
			}
			temp *= temp;
			temp %= mod;
			cnt /= 2;
		}
	}
	if(x!=1){
//		printf("%lld\n", x);
		if(N%x==0) ans*=x, ans%=mod;
	}
	printf("%lld", ans);
}
