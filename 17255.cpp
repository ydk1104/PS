#include<stdio.h>

int dp[10000001];

int ans(int N){
	if(N<10) return 1;
	if(dp[N]) return dp[N];
	int temp = 1;
	while(temp<=N) temp*=10;
	dp[N] = ans(N/10);
	if(N/10 != N%(temp/10)) dp[N] += ans(N%(temp/10));
	return dp[N];
}

int main(void){
	int N;
	scanf("%d", &N);
	printf("%d", ans(N));
}
