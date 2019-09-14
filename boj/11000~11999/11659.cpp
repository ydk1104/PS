#include<stdio.h>

int sum[100001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d", &x);
		sum[i] = sum[i-1] + x;
	}
	while(M--){
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", sum[y] - sum[x-1]);
	}
}
