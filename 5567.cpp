#include<stdio.h>
#include<vector>

std::vector<int> v[501];

void dfs(int visited[], int now, int num){
	if(visited[now] <= num) return;
	visited[now] = num;
	for(const auto& i : v[now]) dfs(visited, i, num+1);
}

int main(void){
	int N, E;
	scanf("%d %d", &N, &E);
	while(E--){
		int x,y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int arr[501] = {0, 1, };
	for(int i=2; i<=N; i++) arr[i] = 3;
	dfs(arr, 1, 0);
	int ans=0;
	for(int i=2; i<=N; i++) ans += arr[i]!=3;
	printf("%d", ans);
}
