#include<stdio.h>

int main(void){
	long long N, K, Q;
	scanf("%lld %d %d", &N, &K, &Q);
	while(Q--){
		long long x, y;
		scanf("%lld %lld", &x, &y);
		long long cnt=0;
		if(K==1){
			cnt = x-y;
			if(cnt<0) cnt=-cnt;
			goto v;
		}
		while(x!=y){
			if(x>y) x=(x+K-2)/K;
			else y=(y+K-2)/K;
			cnt++;
		}
		v:
		printf("%lld\n", cnt);
	}
}
