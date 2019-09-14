#include<stdio.h>

long long dp[1000001];

int main(void){
	int T;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3; i<=1000000; i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		dp[i] %= 1000000009;
	}
	scanf("%d", &T);
	for(;T--;){
		int N;
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}
}
