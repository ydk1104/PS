#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<int> v[1000001];
int dp[1000001][2];

int dfs(int now, int check, int prev){
	if(dp[now][check]) return dp[now][check];
	int sum = check;
	for(auto &i : v[now]) sum += prev==i ? 0 : std::min(dfs(i, 1-check, now), dfs(i, 1, now));
//	printf("%d %d %d\n", now, check, dp[now][check]=sum);
	return dp[now][check] = sum;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	printf("%d", std::min(dfs(1, 0, 0), dfs(1, 1, 0)));
}
