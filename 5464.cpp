#include<stdio.h>
#include<queue>

int cost[101], W[2001], in[2001];
std::priority_queue<int> pq;
std::queue<int> q;

int main(void){
	int N, M, ans=0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%d", &cost[i]), pq.push(-i);
	for(int i=1; i<=M; i++) scanf("%d", &W[i]);
	for(int i=0; i<M*2; i++){
		int x;
		scanf("%d", &x);
		if(x<0){
			pq.push(-in[-x]);
			if(q.size()){
				int x = q.front(); q.pop();
				int now = -pq.top(); pq.pop();
				in[x] = now;
				ans += cost[now] * W[x];
			}
		}
		else{
			if(!pq.size()){
				q.push(x);
				continue;
			}
			int now = -pq.top(); pq.pop();
			in[x] = now;
			ans += cost[now] * W[x];
		}
	}
	printf("%d", ans);
}
