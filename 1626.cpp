#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<std::pair<int, int> > edge[50001];
std::vector<std::pair<int, std::pair<int, int> > > Edge;

int pa[50001];
int find(int x){return pa[x] ? pa[x] = find(pa[x]) : x;}

struct Node{
	int pa[20];
	std::pair<int, int> cost[20];
	bool visited;
}node[50001];

std::pair<int, int> min_pair(const std::pair<int, int>& x, const std::pair<int, int>& y){
	int a[4] = {x.first, x.second, y.first, y.second};
	std::sort(a, a+4);
	int i = 0;
	while(i<3 && a[0]==a[i]) i++;
	return {a[0], a[i]};
}

void dfs(int now, int pa){
	node[now].pa[0] = pa;
	for(int i=0; i<19; i++) node[now].pa[i+1] = node[node[now].pa[i]].pa[i],
							node[now].cost[i+1] = min_pair(node[now].cost[i], node[node[now].pa[i]].cost[i]);
	for(const auto& i : edge[now]){
		if(!visited[i].visited){
			visited[i].visited = true;
			dfs(i, now);
		}
	}
}

int secondMST(){
	int ans = 0;
	node[1].visited = true;
	dfs(1, 0);
	
	for(const auto& i : Edge){
		int cost = i.first; auto now = i.second;
		auto 
	}
	
	return ans;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int x,y,cost;
		scanf("%d %d %d", &x, &y, &cost);
/*		edge[x].push_back({y, cost});
		edge[y].push_back({x, cost}); // */
		Edge.push_back({cost, {x,y}});
	}
	std::sort(Edge.begin(), Edge.end());
	auto merge = [](int x, int y, int cost){
		x = find(x), y = find(y);
		if(x==y) return false;
		edge[x].push_back({y, cost});
		edge[y].push_back({y, cost});
		pa[y] = x;
		return true;
	};
	int min = 0;
	int cnt = 0;
	for(auto& i : Edge){
		int cost = i.first; auto now = i.second;
		if(merge(now.first, now.second, cost)){
			min += cost;
			cnt++;
			i.first = 0;
		}
	}
	if(cnt != N-1){
		printf("-1");
		return 0;
	}
//	printf("%d\n", min);
	int ans = secondMST();
	if(ans == min){
		printf("-1");
		return 0;
	}
}
