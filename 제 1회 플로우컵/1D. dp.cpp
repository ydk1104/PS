#include<stdio.h>
#define INTMAX 1000000007

int main(void){
	int T;
	scanf("%d", &T);
	for(; T>0; T--){
		int N, M;
		scanf("%d %d", &N, &M);
		int dp[11][9][9];
		dp[0][0][0] = 1;
		for(int i=1; i<=N; i++){
			for(int j=1; j<=8; j++){
				for(int k=0; k<=8; k++){
					dp[i][j][k] = dp[i-1][k][
					dp[i][k+j] += dp[i-1][k];
					dp[i][k+j] %= INTMAX;
				}
			}
		}
		int ans = 0;
		for(int i=0; i<=M)
	}
}
