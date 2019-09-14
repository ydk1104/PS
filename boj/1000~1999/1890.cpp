#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	long long int dp[101][101] = {0, };
	dp[1][1] = 1;
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			scanf("%lld", &dp[0][0]);
			if(dp[0][0] != 0){
				if(i+dp[0][0] <=N){
					dp[i+dp[0][0]][j] += dp[i][j];
				}
				if (j+dp[0][0] <= N){
					dp[i][j+dp[0][0]] += dp[i][j];
				}
				
			}
		}
	}
	printf("%lld", dp[N][N]);
}
