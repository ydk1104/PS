#include<stdio.h>

const int NMAX = 1<<18;

struct segeTree{
	int MAX = NMAX;
	int value[NMAX<<1];
	int lazy[NMAX<<2];
	void p(int now, int cnt){
		if(lazy[now]){
			value[now] = cnt-value[now];
			lazy[now*2] ^= 1;
			lazy[now*2+1] ^= 1;
			lazy[now] = 0;
		}
	}
	void update(int l, int r){return update(l, r, 1, MAX, 1);}
	void update(int l, int r, int nl, int nr, int now){
		p(now, nr-nl+1);
		if(l > nr || r < nl) return;
		if(l <= nl && nr <= r){
			lazy[now] ^= 1;
			p(now, nr-nl+1);
			return;
		}
		int mid = (nl+nr)/2;
		update(l, r, nl, mid, now*2); update(l, r, mid+1, nr, now*2+1);
		value[now] = value[now*2] + value[now*2+1];
	}
	int cnt(int l, int r){return cnt(l, r, 1, MAX, 1);}
	int cnt(int l, int r, int nl, int nr, int now){
		if(l > nr || r < nl) return 0;
		p(now, nr-nl+1);
		if(l <= nl && nr <= r) return value[now];
		int mid = (nl+nr)/2;
		return cnt(l, r, nl, mid, now*2) + cnt(l, r, mid+1, nr, now*2+1);
	}
}ST;

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int t,x,y;
		scanf("%d %d %d", &t, &x, &y);
		if(t) printf("%d\n", ST.cnt(x,y));
		else ST.update(x,y);
	}
}
