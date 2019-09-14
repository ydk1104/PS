#include<stdio.h>

int dp[1001][1001];

int min3(int a, int b, int c){
	if(a<b && a<c) return a;
	if(b<c) return b;
	return c;
}

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int main(void){
	int N, M;
	int map;
	int ans = 0;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%1d", &map);
			if(map == 1){
				dp[i][j] = min3(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	printf("%d", ans*ans);
}
