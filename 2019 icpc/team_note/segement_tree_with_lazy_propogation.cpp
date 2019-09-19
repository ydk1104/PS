#include<stdio.h>

const int NMAX = 1<<20;

struct segeTree{
	int MAX = NMAX; // n <= 10^6
	long long value[NMAX<<1];
	long long lazy[NMAX<<2];
	void __init__(int N){
		for(int i=0; i<N; i++) scanf("%lld", &value[i+MAX]);
		for(int i=MAX-1; i; i--) value[i] = value[i*2] + value[i*2+1];
	}
	void p(int now, int cnt){
		if(!lazy[now]) return;
		value[now] += lazy[now] * cnt;
		lazy[now*2] += lazy[now];
		lazy[now*2+1] += lazy[now];
		lazy[now] = 0;
		
	}
	void update(int l, int r, long long x){return update(l, r, 1, MAX, 1, x);}
	void update(int l, int r, int nl, int nr, int now, long long x){
		p(now, nr-nl+1);
		if(l > nr || r < nl) return;
		if(l <= nl && nr <= r){
			lazy[now] += x;
			p(now, nr-nl+1);
			return;
		}
		int mid = (nl+nr)/2;
		update(l, r, nl, mid, now*2, x); update(l, r, mid+1, nr, now*2+1, x);
		value[now] = value[now*2] + value[now*2+1];
	}
	long long sum(int l, int r){return sum(l, r, 1, MAX, 1);};
	long long sum(int l, int r, int nl, int nr, int now){
		if(l > nr || r < nl) return 0;
		p(now, nr-nl+1);
		if(l <= nl && nr <= r) return value[now];
		int mid = (nl+nr)/2;
		return sum(l, r, nl, mid, now*2) + sum(l, r, mid+1, nr, now*2+1);
	}
}ST;

int main(void){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	ST.__init__(N);
	for(int T=1; T<=M+K; T++){
		int t, x, y;
		long long z;
		scanf("%d %d %d", &t, &x, &y);
		if(t==1){
			scanf("%lld", &z);
			ST.update(x,y,z);
		}
		else{
			printf("%lld\n", ST.sum(x,y));
		}
	}
}
