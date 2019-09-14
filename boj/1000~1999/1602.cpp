#include<stdio.h>
#include<algorithm>
#define MAX 1000000000

using namespace std;

pair<int,int> cost[501];
int dp[501][501];
int ans[501][501];
int map[501][501];
int c[501][501];

void test_print(int N){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	int N, M, Q;
	scanf("%d %d %d", &N, &M, &Q);
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d", &x);
		cost[i] = make_pair(x, i);
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			dp[i][j] = MAX;
			ans[i][j] = MAX;
			map[i][j] = MAX;
			c[i][j] = max(cost[i].first, cost[j].first);
		}
	}
	sort(cost+1, cost+N+1);
	for(int i=0; i<M; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		dp[x][y] = min(dp[x][y], z);
		dp[y][x] = min(dp[x][y], z);
	}
	for(int i=1; i<=N; i++) dp[i][i] = 0;
	for(int k=1; k<=N; k++){
		int now = cost[k].second;
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				dp[i][j] = min(dp[i][j], dp[i][now]+dp[now][j]);
				ans[i][j] = min(ans[i][j], dp[i][j] + max(c[i][now], c[now][j]));
			}
		}
	}
	while(Q--){
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", ans[x][y]==MAX ? -1 : ans[x][y]);
	}
}
