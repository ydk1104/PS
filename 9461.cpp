#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	long long int dp[101] = {0, 1, 1, 1, 2, };
	for (int i=5; i<=100; i++){
		dp[i] = dp[i-1] + dp[i-5];
	}
	for (int i=1; i<=T; i++){
		int N;
		scanf("%d", &N);
		printf("%lld\n", dp[N]);
	}
}
