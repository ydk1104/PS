#include<stdio.h>

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	int dp[501];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	for(int i=4; i<=N; i++){
		dp[i] = dp[i/2+1]+1;
	}
	if(K>=dp[N]){
		printf("%d", dp[N]);
		return 0;
	}
	int max = 1;
	max = max<<(K-1);
	N = (N-1)/max+1;
	N += K-1;
	printf("%d", N);
}
