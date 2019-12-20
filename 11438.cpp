#include<stdio.h>
#include<vector>

const int MAX = 100000;

std::vector<int> edge[MAX+1];
bool visited[MAX+1];

struct Node{
	int pa[21] = {0, };
	int depth=0;
}node[MAX+1];

void dfs(int now, int pa){
	if(visited[now]) return;
	visited[now] = true;
	node[now].pa[0] = pa;
	for(int i=1; i<21; i++) {node[now].pa[i] = node[node[now].pa[i-1]].pa[i-1]; if(!node[now].pa[i]) break;}
	node[now].depth = node[pa].depth+1;
	for(const auto& i : edge[now]){
		if(!visited[i]) dfs(i, now);
	}
}

int LCA(int x, int y, int max){
	if(x==y) return x;
	for(int i=max; i>=0; i--) if(node[x].pa[i] != node[y].pa[i])
		x=node[x].pa[i], y=node[y].pa[i];
	if(x != y) x = node[x].pa[0];
	return x;
}
int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(1, 0);
	int Q;
	for(scanf("%d", &Q); Q--;){
		int x,y;
		scanf("%d %d", &x, &y);
		if(node[x].depth > node[y].depth){
			x^=y; y^=x; x^=y;
		}
		for(int i=20; node[x].depth!=node[y].depth; i--){
			if(node[x].depth <= (node[y].depth - (1<<i))) y=node[y].pa[i]; 
		}
		printf("%d\n", LCA(x,y,20));
	}
}
