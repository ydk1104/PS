#include<stdio.h>
#include<vector>
#include<queue>

struct xyz{
	int x,y,z;
};

std::vector<xyz> v;
int cnt[100001], check[100001];
std::queue<int> q[3];
std::vector<std::pair<int, int> > edge[100001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N-2; i++){
		int x,y,z;
		scanf("%d %d %d", &x, &y, &z);
		v.push_back({x,y,z});
		cnt[x]++; cnt[y]++; cnt[z]++;
		edge[x].push_back({y,z});
		edge[y].push_back({z,x});
		edge[z].push_back({x,y});
	}
	for(int i=1; i<=N; i++){
		if(cnt[i]==1){
			q[1].push(i);
			break;
		}
	}
	std::vector<int> ans[2];
	int num = 1;
	while(!q[num].empty()){
		int now = q[num].front(); q[num].pop();
//		printf("%d\n", now);
		if(check[now]) continue;
		check[now] = 1;
		for(auto& i : edge[now]){
			if(cnt[i.first] && cnt[i.second]){
				cnt[i.first]--;
				cnt[i.second]--;
				q[cnt[i.first]].push(i.first);
				q[cnt[i.second]].push(i.second);
			}
		}
//		q[num].pop();
		ans[1].push_back(now);
		while(!q[2].empty()){
			q[1].push(q[2].front());
			q[2].pop();
		}
	}
	for(const auto& i : ans[1]) printf("%d ",i);
	for(int i=1; i<=N; i++) if(!check[i]) printf("%d",i);
}
