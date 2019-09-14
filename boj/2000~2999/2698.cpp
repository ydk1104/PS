#include<stdio.h>

int dp[101][101][2];

int main(void){
	int T;
	scanf("%d", &T);
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	for(int i=1; i<=100; i++){
		for(int j=0; j<i; j++){
			dp[i+1][j][0] += dp[i][j][0] + dp[i][j][1];
			dp[i+1][j][1] += dp[i][j][0];
			dp[i+1][j+1][1] += dp[i][j][1];
		}
	}
	for(; T>0; T--){
		int N, K;
		scanf("%d %d", &N, &K);
		printf("%d\n", dp[N][K][0] + dp[N][K][1]);
	}
	return 0;
}
