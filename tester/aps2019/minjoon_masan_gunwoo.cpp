#include<stdio.h>
#include<vector>
#include<queue>

std::vector<std::pair<int, int> > edge[5001];
int v[5001];
int ans[5001];

int main(void){
	int N, V, S;
	scanf("%d %d %d", &N, &V, &S);
	for(int i=1; i<=N; i++) v[i] = 2e9;
	for(int i=0; i<V; i++){
		int x,y,cost;
		scanf("%d %d %d", &x, &y, &cost);
		edge[x].emplace_back(y,cost);
		edge[y].emplace_back(x,cost);
	}
	std::priority_queue<std::pair<std::pair<int, int>, int> > pq;
	pq.push({{0, 1}, 0});
	while(!pq.empty()){
		auto now = pq.top(); pq.pop();
		int nx = -now.first.first, ny = now.first.second, save = now.second | S==ny;
		if(v[ny] < nx) continue;
		v[ny] = nx;
		ans[ny] |= save;
		for(const auto& i : edge[ny]){
			if(nx + i.second < v[i.first]){
				v[i.first] = nx + i.second;
				pq.push({{-v[i.first], i.first}, save});
			}
			else if(nx + i.second == v[i.first] && save && !ans[i.first]){
				ans[i.first] = save;
				pq.push({{-v[i.first], i.first}, save});
			}
		}
	}
	printf("%s", ans[N] ? "SAVE HIM" : "GOOD BYE");
}
