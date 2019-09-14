#include<stdio.h>
#include<vector>
#define MAX 1000000000
#define min(a,b) ((a)>(b)?(b):(a))

int dp[401][401];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			dp[i][j] = MAX;
		}
	}
	for(int i=0; i<M; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		dp[x][y] = min(dp[x][y], z);
	}
	for(int k=1; k<=N; k++){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	int ans = dp[1][1];
	for(int i=1; i<=N; i++){
		ans = min(ans, dp[i][i]);
	}
	if(ans==MAX) ans=-1;
	printf("%d", ans);
}
