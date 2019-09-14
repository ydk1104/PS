#include<stdio.h>
#include<vector>
#include<queue>

std::vector<int> v[401];

int dfs(int y, int now, int visited[]){
	visited[now]++;
	std::queue<int> q;
	q.push(now);
	while(!q.empty()){
		int now = q.front(); q.pop();
		if(now==y) return 1;
		for(auto i:v[now]){
			if(!visited[i]) q.push(i), visited[i]++;
		}
	}
	return 0;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
	}
	int Q;
	scanf("%d", &Q);
	for(int i=0; i<Q; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		int visited[2][401] = {0,};
		if(dfs(y, x, visited[0])) printf("-1\n");
		else if(dfs(x, y, visited[1])) printf("1\n");
		else printf("0\n");
	}
}
