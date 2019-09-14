#include<stdio.h>
#define INT_MAX 1000000000

int dp[1024][10][200];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=9; i++){
		dp[1<<(i)][i][1] = 1;
	}
	for(int i=2; i<=N; i++){
		for(int j=1; j<=1023; j++){
			dp[j|(1<<1)][1][i] += dp[j][0][i-1];
			dp[j|(1<<1)][1][i] %= INT_MAX;
			for(int k=1; k<=8; k++){
				dp[j|(1<<(k+1))][k+1][i] += dp[j][k][i-1];
				dp[j|(1<<(k+1))][k+1][i] %= INT_MAX;
				dp[j|(1<<(k-1))][k-1][i] += dp[j][k][i-1];
				dp[j|(1<<(k-1))][k-1][i] %= INT_MAX;
			}
			dp[j|(1<<8)][8][i] += dp[j][9][i-1];
			dp[j|(1<<8)][8][i] %= INT_MAX;
		}
	}
	int ans = 0;
	for(int i=0; i<=9; i++){
		ans += dp[1023][i][N];
		ans %= INT_MAX;
	}
	printf("%d", ans);
	return 0;
}
