#include<stdio.h>
#define mod 1000000007

int main(void){
	int N;
	scanf("%d", &N);
	int dp[51] = {1, 1};
	for(int i=2; i<=N; i++){
		dp[i] = dp[i-1] + dp[i-2] + 1;
		dp[i]%=mod;
	}
	printf("%d", dp[N]);
}
