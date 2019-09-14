#include<stdio.h>
#include<string.h>
#define min(a,b) ((a)>(b)?(b):(a))

int main(void){
	int N;
	scanf("%d", &N);
	int cost[4] = {1,2,5,7};
	int dp[100001];
	memset(dp, 1, sizeof(dp));
	dp[0] = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<4; j++){
			dp[i+cost[j]] = min(dp[i+cost[j]], dp[i]+1);
		}
	}
	printf("%d", dp[N]);
}
