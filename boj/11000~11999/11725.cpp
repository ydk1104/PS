#include<stdio.h>
#include<vector>

std::vector<int> v[100001];
int visited[100001];

void dfs(int now, int pa){
	if(visited[now]) return;
	visited[now] = pa;
	for(auto i:v[now]){
		dfs(i, now);
	}
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
	dfs(1, 0);
	for(int i=2; i<=N; i++) printf("%d\n", visited[i]);
}
