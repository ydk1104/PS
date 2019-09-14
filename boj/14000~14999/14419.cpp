#include<stdio.h>
#define ll long long

int N, Q, S, T;
ll a[200020];
ll minus[200020];
ll wind;

ll plus(ll x){
	if(x>0) return -x*S;
	return -x*T;
}

int main(void){
	scanf("%d %d %d %d", &N, &Q, &S, &T);
	for(int i=0; i<=N; i++) scanf("%lld", &a[i]);
	for(int i=0; i<N; i++){
		minus[i] = a[i+1] - a[i];
		wind += plus(minus[i]);
	}
	while(Q--){
		ll l, r, x;
		scanf("%lld %lld %lld", &l, &r, &x);
		wind -= plus(minus[l-1]);
		minus[l-1] += x;
		wind += plus(minus[l-1]);
		if(r==N) goto v;
		wind -= plus(minus[r]);
		minus[r] -= x;
		wind += plus(minus[r]);
		v:
		printf("%lld\n", wind);
	}
}
