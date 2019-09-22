#include<stdio.h>

int x[11], y[11], a[101];

int main(void){
	int T;
	scanf("%d",&T);
	while(T--){
		int N, M;
		scanf("%d %d", &N, &M);
		for(int i=0; i<M; i++) scanf("%d", &x[i]);
		for(int i=0; i<M; i++) scanf("%d", &y[i]);
		for(int i=0; i<N; i++) scanf("%d", &a[i]);
		int bigx=0, smally=0, ans=0;
		for(int i=0; i<N; i++){
			bigx=0, smally=0;
			for(int j=0; j<M; j++){
				int now = a[(i+j)%N];
				if(!bigx && now < x[j]) goto v;
				if(!smally && now > y[j]) goto v;
				if(now > x[j]) bigx=1;
				if(now < y[j]) smally = 1;
			}
			ans++;
			v:;
		}
		printf("%d\n", ans);
	}
}
