#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	long long int dp[91][2]  = {0, };
	dp[1][1] = 1;
	for (int i=2; i<=N; i++){
		dp[i][1] = dp[i-1][0];
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
	}	
	printf("%lld", dp[N][1] + dp[N][0]);
}
