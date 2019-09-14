#include<stdio.h>

int dp[3][100001];

int main(void){
	int N;
	scanf("%d", &N);
	dp[0][0] = 1;
	for(int i=1; i<=N; i++){
		dp[0][i] = dp[0][i-1] + dp[1][i-1] + dp[2][i-1];
		dp[0][i] %= 9901;
		dp[1][i] = dp[0][i-1] + dp[2][i-1];
		dp[1][i] %= 9901;
		dp[2][i] = dp[0][i-1] + dp[1][i-1];
		dp[2][i] %= 9901;
	}
	printf("%d", (dp[0][N]+dp[1][N]+dp[2][N])%9901);
	return 0;
}
