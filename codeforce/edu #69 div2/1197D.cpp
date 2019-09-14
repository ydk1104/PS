#include<stdio.h>
#include<algorithm>

long long dp[300001][11], ans;

int main(void){
	#define int long long
	int N, M, K;
	scanf("%lld %lld %lld", &N, &M, &K);
	for(int i=0; i<=M; i++) dp[0][i] = -K;
	for(int i=1; i<=N; i++){
		int x;
		scanf("%lld", &x);
		dp[i][1] = std::max(x-K, dp[i-1][M]+x-K);
		ans = std::max(ans, dp[i][1]);
		for(int j=2; j<=M; j++){
			dp[i][j] = std::max(x-K, dp[i-1][j-1]+x);
			ans = std::max(ans, dp[i][j]);
		}
	}
	printf("%lld", ans);
}
