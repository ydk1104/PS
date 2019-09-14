#include<stdio.h>
#define ll long long

int main(void){
	int N;
	scanf("%d", &N);
	ll pair=0, nopair=0, ans=0;
	for(int i=1; i<=N; i++){
		ll x;
		scanf("%lld", &x);
		pair = x/2;
		nopair += x%2;
		ll ck = (pair-nopair)/3;
		if(ck>0) pair-=ck, nopair+=ck*2;
		while(pair>nopair) pair--, nopair+=2;
		ans+=pair;
		nopair-=pair;
	}
	printf("%lld", ans);
}
