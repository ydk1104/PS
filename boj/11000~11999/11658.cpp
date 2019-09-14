#include<stdio.h>
#define ll long long

int N, M, t, x1, y1, x2, y2, max=1;
ll x;

struct segeTree{
	ll arr[2048];
	void update(int i, ll x){
		arr[i]=x;
		do{
			i/=2;
			arr[i]=arr[2*i]+arr[2*i+1];
		}while(i);
	}
	ll sum(int nl, int nr, int l, int r, int now){
		if(nl>r || nr<l) return 0;
		if(nl>=l && nr<=r) return arr[now];
		int mid = (nl+nr)/2;
		return sum(nl, mid, l, r, now*2)+sum(mid+1, nr, l, r, now*2+1);
	}
}T[2048];

void update(int i, int j, ll x){
	T[i].update(j, x);
	do{
		i/=2;
		T[i].update(j, T[i*2].arr[j]+T[i*2+1].arr[j]);
	}while(i);
}

void test_print(int x){
	for(int i=1; i<=max*2+1; i++) printf("%d ", T[x].arr[i]);
	printf("test end\n");
}

ll sum(int l, int r, int x1, int x2, int y1, int y2, int now){
//	printf("test : %d %d %d %d\n", l, r, x1, x2);
	if(l>x2 || r<x1) return 0;
	if(l>=x1 && r<=x2) return T[now].sum(1, max+1, y1, y2, 1);
	int mid=(l+r)/2;
	return sum(l, mid, x1, x2, y1, y2, now*2) + sum(mid+1, r, x1, x2, y1, y2, now*2+1);
}

int main(void){
	scanf("%d %d", &N, &M);
	while(max<N-1) max+=max+1; 
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%lld", &x);
			update(i+max, j+max, x);
//			for(int i=1; i<=N+max; i++) test_print(i);
		}
	}
//	for(int i=1; i<=N+max; i++) test_print(i);
	while(M--){
		scanf("%d %d %d", &t, &x1, &y1);
		if(t){
			scanf("%d %d", &x2, &y2);
			printf("%lld\n", sum(1, max+1, x1, x2, y1, y2, 1));
		}
		else{
			scanf("%lld", &x);
			update(x1+max, y1+max, x);
		}
	}
}
