#include<stdio.h>
#define MAXN 500000

struct segeTree{
	int num[3*MAXN]={0,}, max;
	int laze[6*MAXN]={0,};
	void initialize(int N){
		for(int i=1; i<=N; i++){
			int x;
			scanf("%d", &num[max+i]);
		}
		for(int i=max; i; i--){
			num[i] = num[2*i] ^ num[2*i+1];
		}
	}
	void propagate(int now){
		if(now<=max){
			laze[now*2] ^= laze[now];
			laze[now*2+1] ^= laze[now];
		}
		else{
			num[now] ^= laze[now];
		}
		laze[now] = 0;
	}
	void update(int nl, int nr, int now, int left, int right, int value){
		propagate(now);
		if(nl > right || nr < left) return;
		if(nl >= left && nr <= right){
			laze[now] ^= value;
			propagate(now);
			return;
		}
		int mid = (nl+nr)/2;
		update(nl, mid, now*2, left, right, value), update(mid+1, nr, now*2+1, left, right, value);
		num[now] = num[2*now] ^ num[2*now+1];
	}
	int ans(int nl, int nr, int now, int left, int right){
		propagate(now);
		if(nl > right || nr < left) return 0;
		if(nl >= left && nr <= right) return num[now];
		int mid = (nl+nr)/2;
		return ans(nl, mid, now*2, left, right)^ans(mid+1, nr, now*2+1, left, right);
	}
}ST;

int main(void){
	int N;
	scanf("%d", &N);
	ST.max=1;
	while(ST.max<=N) ST.max+=ST.max+1;
	ST.initialize(N);
	for(scanf("%d", &N);N--;){
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);
		a++; b++;
		if(a>b){
			int temp=a;
			a=b;
			b=temp;
		}
		if(t==2){
			printf("%d\n", ST.ans(1, ST.max+1, 1, a, b));
		}
		else{
			int c;
			scanf("%d", &c);
			ST.update(1, ST.max+1, 1, a, b, c);
		}
	}
}
