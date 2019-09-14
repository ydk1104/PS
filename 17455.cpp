#include<stdio.h>
#include<vector>
#include<algorithm>

int m[128];
std::vector<int> v[200001];
int visited[200001];
int dp[200001];
char s[200001];

int dfs(int now){
	if(visited[now]){
		return dp[now] = 0;
	}
	if(~dp[now]) return dp[now];
	visited[now] = 1;
	int temp = 0;
	for(auto i:v[now]){
		int T = dfs(i);
		if(T) temp = std::max(temp, T);
		else{
			temp = -1;
			break;
		}
	}
	visited[now] = 0;
	return dp[now] = temp + 1;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	scanf("%s", &s);
	char temp[4] = "KDH";
	for(int i=0; i<3; i++) m[temp[i]] = i;
	for(int i=0; i<N; i++) dp[i] = -1;
	for(int i=0; i<M; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		x--; y--;
		int gap = m[s[x]] - m[s[y]];
		if(gap == 1 || gap == -2) v[y].push_back(x);
		if(gap == 2 || gap == -1) v[x].push_back(y);
	}
	int ans=0;
	for(int i=0; i<N; i++){
		if(s[i] == 'K'){
			int tempi = dfs(i);
			if(tempi) ans = std::max(ans, tempi);
			else{
				ans = 0;
				break;
			}
		}
	}
	ans = ans/3*3;
	printf("%d", ans ? ans : -1);
}
