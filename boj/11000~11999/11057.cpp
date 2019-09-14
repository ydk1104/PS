#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int dp[1002][10] = {1, };
	for (int i=1; i<=N+1; i++){
		for(int j=0; j<=9; j++){
			for (int k=0; k<=j; k++){
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= 10007;
			}
		}
	}
	printf("%d", dp[N+1][9]);
}
