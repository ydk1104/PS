#include<stdio.h>
#include<vector>
#include<tuple>
#include<queue>

using ll = long long;

const ll MAX = 1LL << 50;

int main(void){
	int T, N, M, K, start, end;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		ll visited[100001];
		std::vector<std::pair<int, int> > edge[200001];
		scanf("%d %d %d", &N, &M, &K);
		for(int i=0; i<N; i++) visited[i] = MAX;
		for(int i=0; i<M; i++){
			int x,y,cost;
			scanf("%d %d %d", &x, &y, &cost);
			edge[x].push_back({cost,y});
			edge[y].push_back({cost,x});
		}
		scanf("%d %d", &start, &end);
		std::priority_queue<std::pair<ll, int> > pq;
		pq.push({0, start});
		while(!pq.empty()){
			std::pair<ll, int> now = pq.top(); pq.pop();
			while(visited[now.second] != MAX) {now = pq.top(); pq.pop();};
			visited[now.second] = -now.first;
			if(now.second == end) break;
			for(auto &i:edge[now.second]){
				if(visited[i.second] == MAX) pq.push({-(i.first+visited[now.second]), i.second});
			}
		}
		printf("#%d %lld\n",t,visited[end]);
	}
}
