#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<pair<int, int> >v[10001];
pair<int, int> ans[10001];
int visited[10001];

void dfs(int now){
	if(visited[now]) return;
	visited[now]++;
	
}

int main(void){
	int N, x, y, cost;
	scanf("%d", &N);
	for(int i=1; i<N; i++) scanf("%d %d %d", &x, &y, &cost), v[x].push_back(make_pair(y, cost)), v[y].push_back(make_pair(x, cost));
	dfs(1);
	dfs()
}
