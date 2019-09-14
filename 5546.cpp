#include<stdio.h>

int day[101];
int dp[101][4][2];

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=1; i<=K; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		day[A] = B;
	}
	for(int i=1; i<=N; i++){
		if(i==1){
			if(day[i] == 0){
				dp[i][1][0] = 1;
				dp[i][2][0] = 1;
				dp[i][3][0] = 1;
			}
			else{
				dp[i][day[i]][0] = 1;
			}
		}
		else if(day[i] != 0){
			dp[i][day[i]][0] += dp[i-1][day[i]%3+1][0] + dp[i-1][(day[i]+1)%3+1][0];
			dp[i][day[i]][0] += dp[i-1][day[i]%3+1][1] + dp[i-1][(day[i]+1)%3+1][1];
			dp[i][day[i]][0] %= 10000;
			dp[i][day[i]][1] += dp[i-1][day[i]][0];
			dp[i][day[i]][1] %= 10000;
		}
		else{
			for(int j=1; j<=3; j++){
				dp[i][j][0] += dp[i-1][j%3+1][0] + dp[i-1][(j+1)%3+1][0];
				dp[i][j][0] += dp[i-1][j%3+1][1] + dp[i-1][(j+1)%3+1][1];
				dp[i][j][0] %= 10000;
				dp[i][j][1] += dp[i-1][j][0];
				dp[i][j][1] %= 10000;
			}
		}
	}
	int sum = 0;
	for(int i=1; i<=3; i++){
		sum += dp[N][i][0];
		sum += dp[N][i][1];
		sum %= 10000;
	}
	printf("%d", sum);
}
