#include<stdio.h>

int main(void){
	long long N, K;
	scanf("%lld %lld", &N, &K);
	long long ans=0;
	for(int i=1; i<=N; i++){
//		printf("%d %d %d %d %d\n", K, i, K/i, K%i, ans);
		long long p=K/i, q=K%i;
		if(p>q) ans+=q;
		else if(p){
			long long cnt = q/p;
			if(i+cnt>=N) cnt=N-i;
			ans += (q+(q-cnt*p))*(cnt+1)/2;
			i+=cnt;
		}
		else{
			ans += (N-i+1)*K;
			i=N;
		}
	}
	printf("%lld",ans);
}
