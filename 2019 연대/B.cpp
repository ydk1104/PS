#include<stdio.h>
#include<vector>

std::vector<int> v[500001];
int visited[500001];

double leaf;

int dfs(int now){
	if(visited[now]) return 0;
	visited[now]++;
	int check=0;
	for(auto i : v[now]){
		check += dfs(i);
	}
	if(!check) leaf++;
	return 1;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	printf("%f", (double)M/leaf);
}
