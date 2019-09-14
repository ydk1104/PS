#include<stdio.h>
#include<string.h>
#include<vector>
#include<tuple>
#include<queue>

std::vector<std::pair<int, int> > edge[1001];
std::priority_queue<std::pair<int, int> > pq;
std::queue<std::pair<int, int> > ans;
int visited[1001];
int prev[1001];
int check[1001][1001];
const int MAX = 100000;

int checking(int x, int y){
	return check[x][y] | check[y][x];
}

void dijk(){
	int cost, com;
	v:
		if(pq.empty()) return;
		std::pair<int, int> now = pq.top(); pq.pop();
		cost=-now.first, com=now.second;
//		printf("test : %d %d\n", cost, com);
		if(visited[com] < cost) goto v;
	if(!checking(com, prev[com])) ans.push(std::make_pair(com, prev[com]));
	check[com][prev[com]] = check[prev[com]][com] = 1;
	for(auto i : edge[com]){
//		printf("%d %d\n", i.first, i.second);
		if(visited[i.first] > cost + i.second){
			visited[i.first] = cost + i.second;
			prev[i.first] = com;
			pq.push(std::make_pair(-visited[i.first], i.first));
		}
	}
	return dijk();
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	memset(visited, 1, sizeof(visited));
	for(int i=0; i<M; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		edge[x].push_back(std::make_pair(y,z));
		edge[y].push_back(std::make_pair(x,z));
	}
	pq.push(std::make_pair(0, 1));
	dijk();
	ans.pop();
	printf("%d\n", ans.size());
	while(!ans.empty()){
		printf("%d %d\n", ans.front().first, ans.front().second);
		ans.pop();
	}
}
