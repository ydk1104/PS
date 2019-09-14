#include<stdio.h>
#define INT 1000000007

int dp[1001][1001];

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	dp[1][1] = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			dp[i][j] += dp[i-1][j] + dp[i][j-1];
			dp[i][j] %= INT;
			dp[i][j] += dp[i-1][j-1];
			dp[i][j] %= INT;
		}
	}
	printf("%d", dp[n][m]);
}
