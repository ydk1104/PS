#include<stdio.h>
#include<vector>
#include<queue>
#define min(a,b) ((a)>(b)?(b):(a))
#define MAX 1000000000
using namespace std;

struct edge{
	int v;
	int cost;
	int time;
	edge(int a, int b, int c){
		v = a; cost = b; time = c;
	}
	edge(){
		v = 0; cost = 10001; time = 0;
	}
	bool operator <(const edge &x)const{
		return this->time > x.time;
	}
};
int visited[101][10001];

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);
		vector<edge> V[101];
		while(K--){
			int u, v, c, d;
			scanf("%d %d %d %d", &u, &v, &c, &d);
			edge temp(v, c, d);
			V[u].push_back(temp);
		}
		priority_queue<edge> pq; // V, cost, time
		edge temp(1, 0, 0);
		pq.push(temp);
		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				visited[i][j] = MAX;
			}
		}
		int flag = 0;
		while(!pq.empty()){
			edge now = pq.top(); pq.pop();
//			printf("%d %d %d\n", now.v, now.cost, now.time);
			while(!pq.empty() && ( now.time > visited[now.v][now.cost])) now = pq.top(), pq.pop();
			if(now.v == N){
				printf("%d\n", now.time);
				flag = 1;
				break;
			}
			for(vector<edge>::iterator p=V[now.v].begin(); p!=V[now.v].end(); p++){
				edge temp(p->v, now.cost+p->cost, now.time+p->time);
				if(temp.cost > M) continue;
				if(visited[temp.v][temp.cost] <= temp.time) continue;
				visited[temp.v][temp.cost] = temp.time;
				pq.push(temp);
			}
		}
		if(!flag)printf("Poor KCM\n");
		while(!pq.empty()) pq.pop();
	}
}
