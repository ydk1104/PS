#include<stdio.h>

int sum[100001], N, x, y;

int main(void){
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &x), sum[i]=sum[i-1]+x;
	scanf("%d", &N);
	while(N--){
		scanf("%d %d", &x, &y);
		printf("%d\n", sum[y]-sum[x-1]);
	}
}
