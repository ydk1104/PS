#include<stdio.h>

int dp[1001][1001];

int max(int a, int b){
	if (a>b) return a;
	return b;
}

int main(void){
	int N;
	scanf("%d", &N);
	for (int i=1; i<=N; i++){
		int t;
		scanf("%d", &t);
		for (int j=1000; j>t; j--){
			dp[i][j] = dp[i-1][j];
			dp[i][t] = max(dp[i][t], dp[i][j]);
		}
		dp[i][t] ++;
		for (int j=t-1; j>0; j--){
			dp[i][j] = dp[i-1][j];
		}
	}
	int ans = 0;
	for (int i=1; i<=1000; i++){
		ans = max(ans, dp[N][i]);
	}
	printf("%d", ans);
	
}
