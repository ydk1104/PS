#include<stdio.h>

int box[1001];
int dp[1001][1001];

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &box[i]);
	}
	for(int i=1; i<=N; i++){
		int big = 0;
		for(int j=1; j<i; j++){
			dp[i][j] = dp[i-1][j];
			if(box[j]<box[i]){
				big = max(big, dp[i][j]);
			}
		}
		dp[i][i] = big+1;
	}
	int ans = 0;
	for(int i = 1; i<=N; i++){
	 ans = max(ans, dp[N][i]);
	}
	printf("%d", ans);
}
