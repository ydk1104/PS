#include<stdio.h>
#define ll long long

ll segeTree[4000001];
int max=1;

void update(int i, ll x){
	segeTree[i] = x;
	for(i/=2; i>0; i/=2){
		segeTree[i] = segeTree[i*2] + segeTree[i*2+1];
	}
}

ll sum(int left, int right, int now, int nl, int nr){
	if(left <= nl && right >= nr) return segeTree[now];
	if(left > nr || right < nl) return 0;
	ll nowsum = 0;
	nowsum += sum(left, right, now*2, nl, (nl+nr)/2);
	nowsum += sum(left, right, now*2+1, (nl+nr)/2+1, nr);
	return nowsum;
}

int main(void){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	while(N>max) max*=2;
//	max/=2;
	for(int i=1; i<=N; i++){
		ll x;
		scanf("%lld", &x);
		update(max+i-1, x);
	}
	for(int i=0; i<M+K; i++){
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if(a==1){
			update(max+b-1, c);
		}
		else{
			printf("%lld\n", sum(b, c, 1, 1, max));
		}
	}
}
