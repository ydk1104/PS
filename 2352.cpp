#include<stdio.h>
#include<algorithm>

struct segeTree{
	int arr[1<<20] = {0,};
	int MAX = 1<<19;
	void update(int x, int value){
		x+=MAX;
		arr[x] = value;
		while(x){
			x/=2;
			arr[x] = std::max(arr[x*2],arr[x*2+1]);
		}
	}
	int max(int l, int r, int nl, int nr, int now){
		if(r < nl || l > nr) return 0;
		if(l <= nl && nr <= r) return arr[now];
		int mid=(nl+nr)/2;
		return std::max(max(l, r, nl, mid, now*2), max(l, r, mid+1, nr, now*2+1));
	}
}ST;

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		ST.update(x, ST.max(1, x, 1, ST.MAX, 1)+1);
	}
	printf("%d", ST.arr[1]);
}
