#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

void test_print(long long dp[][101]){
	for(int i=1; i<=101; i++) printf("%lld ", dp[i][0]);
	printf("\n");
}

int main(void){
	int N;
	scanf("%d", &N);
	long long dp[101][101] = {};
	for(int i=1; i<=N; i++) dp[i][0] = dp[i][1] = i;
	for(int j=3; j<=N; j++){
		dp[j-1][j] = dp[j-2][0];
		dp[j][j] = dp[j-2][0];
		for(int i=j+1; i<=N; i++){
			dp[i][j] = max(dp[i-3][0]+dp[j][j],dp[i-1][j]+dp[j][j]);
//			printf("%d %d %d %d\n", i, j, dp[i][j], dp[j][j]);
		}
		for(int i=1; i<=N; i++){
			dp[i][0] = max(dp[i][0], dp[i][j]);
		}
//		test_print(dp);
	}
	printf("%lld", dp[N][0]);
}
