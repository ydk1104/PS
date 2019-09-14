#include<stdio.h>
int N, M, x, a, b, c, d, sum[1025][1025];

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &x);
			sum[i][j] = x+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
	while(M--){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", sum[c][d] - sum[a-1][d] - sum[c][b-1] + sum[a-1][b-1]);
	}
}
