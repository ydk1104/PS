#include<stdio.h>
#include<algorithm>

int a[200001];
int sum[200001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%d", &a[i]);
	for(int i=1; i<=N; i++){
		sum[i] = sum[i-1] + a[i];
	}
	for(int i=1; i<=M; i++){
		int x;
		scanf("%d", &x);
		int now = std::lower_bound(sum, sum+N+1, x)-sum;
		if(sum[now]!=x) now--;
		printf("%d\n", now);
	}
}
