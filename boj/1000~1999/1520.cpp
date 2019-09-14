#include<stdio.h>

int N, M;
int map[502][502];
int dp[502][502];

int find(int a, int b){
	if (dp[a][b] != -1) return dp[a][b];
	dp[a][b] = 0;
	if (a==N && b==M){
		dp[a][b] = 1;
		return dp[a][b];
	}
	if(a==0 || a>N || b==0 || b>M){
		dp[a][b] = 0;
		return dp[a][b];
	}
	if (map[a][b] > map[a-1][b]){
		dp[a][b] += find(a-1, b);
	}
	if (map[a][b] > map[a+1][b]){
		dp[a][b] += find(a+1, b);
	}
	if (map[a][b] > map[a][b-1]){
		dp[a][b] += find(a, b-1);
	}
	if (map[a][b] > map[a][b+1]){
		dp[a][b] += find(a, b+1);
	}
	return dp[a][b];
}

int main(void){
	scanf("%d %d", &N, &M);
	for (int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	}
	find(1,1);
	printf("%d", dp[1][1]);
}
