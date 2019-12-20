#include<stdio.h>
#include<vector>

const int MAX = 40000;

std::vector<std::pair<int, int> > edge[MAX+1];
bool visited[MAX+1];

struct Node{
	int pa[21] = {0, };
	int cost[21] = {0, };
	int depth=0;
}node[MAX+1];

void dfs(int now, int pa, int cost){
	if(visited[now]) return;
	visited[now] = true;
	node[now].pa[0] = pa;
	node[now].cost[0] = cost;
	for(int i=1; i<21; i++) {
		node[now].pa[i] = node[node[now].pa[i-1]].pa[i-1];
		node[now].cost[i] = node[node[now].pa[i-1]].cost[i-1] + node[now].cost[i-1];
		if(!node[now].pa[i]) break;
	}
	node[now].depth = node[pa].depth+1;
	for(const auto& i : edge[now]){
		if(!visited[i.first]) dfs(i.first, now, i.second);
	}
}

int LCA(int x, int y, int max){
	if(x==y) return 0;
	int temp = 0;
	for(int i=max; i>=0; i--) if(node[x].pa[i] != node[y].pa[i])
		temp += node[x].cost[i]+node[y].cost[i], x=node[x].pa[i], y=node[y].pa[i];
	if(x != y) temp += node[x].cost[0]+node[y].cost[0];
	return temp;
}
int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int x,y,z;
		scanf("%d %d %d", &x, &y, &z);
		edge[x].push_back({y,z});
		edge[y].push_back({x,z});
	}
	dfs(1, 0, 0);
	int Q;
	for(scanf("%d", &Q); Q--;){
		int x,y;
		scanf("%d %d", &x, &y);
		if(node[x].depth > node[y].depth){
			x^=y; y^=x; x^=y;
		}
		int ans = 0;
		for(int i=20; node[x].depth!=node[y].depth; i--){
			if(node[x].depth <= (node[y].depth - (1<<i))) ans += node[y].cost[i], y=node[y].pa[i]; 
		}
		printf("%d\n", ans + LCA(x,y,20));
	}
}
