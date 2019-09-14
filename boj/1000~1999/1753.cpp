#include<stdio.h>
#include<queue>
#include<vector>
#define MAX 1000000000

using namespace std;

vector<pair<int, int> > v[20001];// tar, cost
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // cost, node
int ans[20001];
int check[20001];

void dijk(){
	while(!pq.empty()){
		pair<int, int> temp = pq.top(); pq.pop();
		if(check[temp.second]) return dijk();
		check[temp.second] = 1;
		for(vector<pair<int, int> >::iterator p = v[temp.second].begin(); p != v[temp.second].end(); p++){
			int nowcost = temp.first + p->second;
			if(ans[p->first] > nowcost){
				ans[p->first] = nowcost;
				pq.push(make_pair(nowcost, p->first));
			}
		}
	}
}

int main(void){
	int N, M, start;
	scanf("%d %d\n%d", &N, &M, &start);
	for(int i=1; i<=N; i++) ans[i] = MAX;
	for(int i=0; i<M; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back(make_pair(y, z));
	}
	ans[start] = 0;
	pq.push(make_pair(0, start));
	dijk();
	for(int i=1; i<=N; i++){
		if(ans[i] == MAX) printf("INF\n");
		else printf("%d\n", ans[i]);
	}
}
