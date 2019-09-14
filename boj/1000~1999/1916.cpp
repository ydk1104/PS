#include<stdio.h>
#include<queue>
#include<algorithm>
#define MAX 1000000000

using namespace std;

vector<vector<pair<int, int> > >v(1001, vector<pair<int, int> >(0));
int dist[1001][1001];

int dijk(int start, int end){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, start));
	int check[1001] = {0, };
	for(int i=0; i<=1000; i++){
		for(int j=0; j<=1000; j++) dist[i][j] = MAX;
	}
	dist[start][start] = 0;
	check[start]=1;
	while(!pq.empty()){
		pair<int, int> now = pq.top(); pq.pop();
		if(now.second == end) return now.first;
		check[now.second] = 1;
		for(vector<pair<int, int> >::iterator p=v[now.second].begin(); p!=v[now.second].end(); p++){
			if(dist[now.second][p->first] > now.first+p->second){
				dist[now.second][p->first] = now.first+p->second;
				pq.push(make_pair(dist[now.second][p->first], p->first));
			}
		}
	}
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back(make_pair(y, z));
	}
	int start, end;
	scanf("%d %d", &start, &end);
	printf("%d", dijk(start, end));
}
