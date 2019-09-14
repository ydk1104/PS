#include<stdio.h>

int dp[1001][1001];

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int main(void){
	int N;
	scanf("%d", &N);
	int a[1001] = {0, };
	for (int i=1; i<=N; i++){
		scanf("%d", &a[i]);
		a[0] = max(a[0], a[i]);
		for (int j=1; j<a[i]; j++){
			dp[i][j] = dp[i-1][j];
			dp[i][a[i]] = max(dp[i][a[i]], dp[i-1][j]);
		}
		dp[i][a[i]] += a[i];
		for (int j=a[i]+1; j<=a[0]; j++){
			dp[i][j] = dp[i-1][j];
		}
	}
	int ans = 0;
	for (int i=1; i<=1000; i++){
		ans = max(ans, dp[N][i]);
	}
	printf("%d", ans);
}
