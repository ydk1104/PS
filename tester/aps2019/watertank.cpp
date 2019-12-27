#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<int> v[200001];

struct Node{
	int pa, depth, water=0;
}node[200001];

void dfs(int now, int prev){
	if(node[now].depth) return;
	node[now].pa = prev;
	node[now].depth = node[prev].depth+1;
	for(const auto& i : v[now]) dfs(i, now);
}

void water(int x){
	while(node[x].depth){
		node[x].water += node[x].depth;
		x = node[x].pa;
	}
}

int ans(int x){
	return node[x].water;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N-1; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(M, 0);
	int Q;
	scanf("%d", &Q);
	while(Q--){
		int type, x;
		scanf("%d %d", &type, &x);
		if(type==1){
			water(x);
		}
		else{
			printf("%d\n", ans(x));
		}
	}
}
