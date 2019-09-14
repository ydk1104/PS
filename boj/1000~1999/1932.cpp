#include<stdio.h>

int max(int a, int b){
	if (a>b) return a;
	return b;
}

int main(void){
	int N;
	scanf("%d", &N);
	int tri[502][502] = {0, };
	int dp[502][502] = {0, };
	for (int i=1; i<=N; i++){
		for (int j=1; j<=i; j++){
			scanf("%d", &tri[i][j]);
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];
		}
	}
	int ans = 0;
	for (int i=1; i<=N; i++){
		ans = max(ans, dp[N][i]);
	}
	printf("%d", ans);
	return 0;	
}
