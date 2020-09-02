#include<stdio.h>
#include<algorithm>

struct segeTree{
	int arr[3000000];
	const int MAX = 1<<20;
	void update(int idx, int value){
		idx += MAX;
		while(idx){
			if(arr[idx] < value) arr[idx] = value;
			idx/=2;
		}
	}
	int max(int l, int r){return max(l, r, 1, MAX, 1);}
	int max(int l, int r, int nl, int nr, int now){
		if(nl > r || r < nl) return 0;
		if(l <= nl && nr <= r) return arr[now];
		int mid = (nl+nr)/2;
		return std::max(max(l, r, nl, mid, now*2), max(l, r, mid+1, nr, now*2+1));
	}
}ST;

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		ST.update(x, ST.max(1, x)+1);
	}
	printf("%d", ST.arr[1]);
}
