#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int dp[1001];
	dp[0] = 1;
	dp[1] = 1;
	for (int i=2; i<=N; i++){
		dp[i] = dp[i-1] + dp[i-2];
		dp[i] %= 10007;
	}
	printf("%d", dp[N]);
}
