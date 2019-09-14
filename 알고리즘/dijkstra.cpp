#include<stdio.h>
#include<vector>
#include<queue>

const int V_MAX = 1000;
const int edge_MAX = 1000;

class dijk{
	private:
		int N, M, start=1;
		std::vector<std::pair<int, int> > edge[edge_MAX+1];
		int visited[V_MAX+1];
	public:
		void scan(){
			scanf("%d %d", &N, &M);
			for(int i=0; i<M; i++){
				int x, y, cost;
				scanf("%d %d %d", &x, &y, &cost);
				edge[x].push_back({y, cost});
				edge[y].push_back({x, cost});
			}
		}
		void process(){
			std::priority_queue<std::pair<int, int> > pq;
			pq.push({start, 0});
			while(!pq.empty()){
				std::pair<int, int> now = pq.top(); pq.pop();
				now.second = -now.second;
				for(auto i:edge[now.first]){
					int cost = now.second + i.second;
					if(visited[now.first] > cost){
						visited[now.first] = cost;
						pq.push(now.first, -cost);
					}
				}
			}
		}
		void print(){
			
		}
}dijk;

int main(void){
	dijk.scan();
	dijk.process();
	dijk.print();
}
