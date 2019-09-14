#include<stdio.h>
#define max(a,b) ((a)>(b) ? (a) : (b))

int map[1001][1001];
int dp[1001][1001][3];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 0){
				dp[i][j][0] = max(dp[i-1][j][2], dp[i][j-1][2]) + 1;
				dp[i][j][0] = max(dp[i][j][0], max(dp[i-1][j][0], dp[i][j-1][0]));
				dp[i][j][1] = max(dp[i-1][j][1], dp[i][j-1][1]);
				dp[i][j][2] = max(dp[i-1][j][2], dp[i][j-1][2]);
			}
			else{
				dp[i][j][map[i][j]-1] = max(dp[i-1][j][map[i][j]-1], dp[i][j-1][map[i][j]-1]);
				dp[i][j][(map[i][j]+1)%3] = max(dp[i-1][j][(map[i][j]+1)%3], dp[i][j-1][(map[i][j]+1)%3]);
				dp[i][j][map[i][j]] = max(dp[i-1][j][map[i][j]], dp[i][j-1][map[i][j]]);
				if(dp[i-1][j][map[i][j]-1]) dp[i][j][map[i][j]] = max(dp[i][j][map[i][j]], dp[i-1][j][map[i][j]-1]+1);
				if(dp[i][j-1][map[i][j]-1]) dp[i][j][map[i][j]] = max(dp[i][j][map[i][j]], dp[i][j-1][map[i][j]-1]+1);
			}
		}
	}
	printf("%d", max(max(dp[N][N][0], dp[N][N][1]), dp[N][N][2]));
}
