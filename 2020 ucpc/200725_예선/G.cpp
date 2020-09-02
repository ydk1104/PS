#include<stdio.h>
#include<queue>
#include<vector>

std::vector<int> v[200001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	while(M--){
		int x,y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	std::queue<std::pair<int, int > > q;
	int cnt[200001] = {0, };
	int time[200001] = {0, };
	for(int i=1; i<=N; i++) time[i] = -1;
	for(int i=0; i<M; i++){
		int x;
		scanf("%d", &x);
		q.push({x,time[x] = 0});
	}
	
	int c=0;
	while(q.size()){
		auto now = q.front(); q.pop();
//		time[now.first] = now.second;
		for(auto i : v[now.first]){
			cnt[i]++;
			if(cnt[i] * 2 >= v[i].size() && time[i]==-1) q.push({i, time[i] = now.second+1});
		}
		c++;
	}
	printf("%d",c);
}
