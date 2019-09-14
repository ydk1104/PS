#include<stdio.h>

int max(int a, int b){
	if (a>b) return a;
	return b;
}

int max3(int a, int b, int c){
	if (a>b && a>c) return a;
	if (b>c) return b;
	return c;
}

int main(void){
	int T;
	scanf("%d", &T);
	for (int ii=1; ii<=T; ii++){
		int N;
		scanf("%d", &N);
		int score[100001][2];
		int dp[100001][3] = {0, };
		for (int i=0; i<=1; i++){
			for (int j=1; j<=N; j++){
				scanf("%d", &score[j][i]);
			}
		}
		for (int j=1; j<=N; j++){
			dp[j][0] = max3(dp[j-1][0], dp[j-1][1], dp[j-1][2]);
			dp[j][1] = max(dp[j-1][0], dp[j-1][2]) + score[j][0];
			dp[j][2] = max(dp[j-1][0], dp[j-1][1]) + score[j][1];
		}
		printf("%d\n", max3(dp[N][0], dp[N][1], dp[N][2]));
	}
	return 0;
}
