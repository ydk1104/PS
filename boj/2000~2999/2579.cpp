#include<stdio.h>

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int main(void){
	
	int N;
	int score[301];
	int dp[301][3] = {0, };
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &score[i]);
	}
	dp[1][1] = score[1];
	dp[2][1] = score[2];
	dp[2][2] = score[1] + score[2];
	for (int i=3; i<=N; i++){
		dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + score[i];
		dp[i][2] = dp[i-1][1] + score[i];
	}
	printf("%d", max(dp[N][1], dp[N][2]));
}
