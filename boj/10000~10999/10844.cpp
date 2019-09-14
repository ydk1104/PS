#include<stdio.h>
#define INT 1000000000

int main(void){
	int N;
	scanf("%d", &N);
	int dp[101][10] = {0, };
	for (int i=1; i<=9; i++){
		dp[1][i] = 1;
	}
	for (int i=2; i<=N; i++){
		for (int j=0; j<=9; j++){
			if (j==0){
				dp[i][j] = dp[i-1][j+1];
			}
			else if (j==9){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
			}
			dp[i][j] %= INT;
		}
	}
	int ans = 0;
	for (int i=0; i<=9; i++){
		ans += dp[N][i];
		ans %= INT;
	}
	printf("%d", ans);
}
