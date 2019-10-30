#include<stdio.h>

class segeTree{
	public:
		int MAX=1;
		long long arr[1<<22] = {0,};
		long long start[1<<20];
		long long lazy[1<<23];
	public:
		void init(int N){
			while(MAX < N) MAX <<= 1;
			for(int i=0; i<N; i++) scanf("%lld", &start[i]);
		}
		void p(int now, int cnt){
			if(!lazy[now]) return;
			arr[now] += lazy[now] * cnt;
			lazy[now*2] += lazy[now];
			lazy[now*2+1] += lazy[now];
			lazy[now] = 0;
		}
		void update(int left, int right, int plus){
			return update(left, right, 1, MAX, 1, plus);
		}
		void update(int l, int r, int nl, int nr, int now, int plus){
			p(now, nr-nl+1);
			if(l > nr || r < nl) return;
			if(l <= nl && nr <= r){
				lazy[now] += plus;
				p(now, nr-nl+1);
				return;
			}
			int mid = (nl+nr)/2;
			update(l, r, nl, mid, now*2, plus); update(l, r, mid+1, nr, now*2+1, plus);
			arr[now] = arr[now*2] + arr[now*2+1];
		}
		long long sum(int left, int right){
			return sum(left, right, 1, MAX, 1) + start[right-1];
		}
		long long sum(int l, int r, int nl, int nr, int now){
			if(l > nr || r < nl) return 0;
			p(now, nr-nl+1);
			if(l <= nl && nr <= r){
				return arr[now];
			}
			int mid = (nl+nr)/2;
			return sum(l, r, nl, mid, now*2) + sum(l, r, mid+1, nr, now*2+1);
		}
}ST;

int main(void){
	int N;
	scanf("%d", &N);
	ST.init(N);
	int Q;
	scanf("%d", &Q);
	while(Q--){
		int type,x,y;
		scanf("%d %d", &type, &x);
		if(type==1){
			scanf("%d", &y);
			ST.update(x, y, 1);
			ST.update(y+1, y+1, -y-1+x);
		}
		else{
			printf("%lld\n", ST.sum(1, x));
		}
	}
}
