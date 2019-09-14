#include<stdio.h>
#include<queue>
#include<functional>

std::pair<int, int> dir[] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
std::priority_queue<std::pair<int, std::pair<int, int> >, std::vector<std::pair<int, std::pair<int, int> > >, std::greater<std::pair<int, std::pair<int, int> > > > pq;
int notVisited[402][402];
int map[402][402];
int cost[402][402];

int main(){
	int N, M, k, r, c;
	scanf("%d %d %d %d %d", &N, &M, &k, &r, &c);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%d", &map[i][j]);
			notVisited[i][j] = 1;
			cost[i][j] = 1e8;
		}
	}
	std::pair<int, int> now = {r+1,c+1};
	pq.push({k, now});
	while(!pq.empty()){
		auto now = pq.top(); pq.pop();
//		printf("%d %d %d\n", now.first, now.second.first, now.second.second);
		if(!notVisited[now.second.first][now.second.second]) continue;
		notVisited[now.second.first][now.second.second] = 0;
		cost[now.second.first][now.second.second] = now.first;
		for(int i=0; i<4; i++){
			std::pair<int, int> to = {now.second.first + dir[(i + map[now.second.first][now.second.second] + now.first + 1)%4].first, now.second.second + dir[(i + map[now.second.first][now.second.second] + now.first + 1)%4].second};
			if(notVisited[to.first][to.second] && now.first + i + 1 < cost[to.first][to.second]) pq.push({cost[to.first][to.second]=now.first + i + 1, to});
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			printf("%d ",cost[i][j]);
		}
		printf("\n");
	}
}
