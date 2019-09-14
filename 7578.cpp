#include<stdio.h>
#include<map>

std::map<int, int> memo;

struct segeTree{
	int arr[1<<24];
	int max = 1<<23;
	void update(int x, int value){
		x += max;
		arr[x] = value;
		while(x){
			x/=2;
			arr[x] = arr[x*2] + arr[x*2+1];
		}
	}
	int sum(int l, int r, int nl, int nr, int now){
		if(r < nl || nr < l) return 0;
		if(l <= nl && nr <= r) return arr[now];
		int mid = (nl+nr)/2;
		return sum(l, r, nl, mid, now*2) + sum(l, r, mid+1, nr, now*2+1);
	}
}ST;

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		memo[x] = i;
	}
	long long ans=0;
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		int now = memo[x];
		ans += ST.sum(now+1, ST.max, 1, ST.max, 1);
		ST.update(now, 1);
	}
	printf("%lld", ans);
}
