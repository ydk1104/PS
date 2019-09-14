#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int dp[31] = {1, };
	for (int i=2; i<=N; i++){
		dp[i] += 3*dp[i-2];
		for (int j=4; j<=i; j+=2){
			dp[i] += 2 * dp[i-j];
		}
	}
	printf("%d", dp[N]);
}
