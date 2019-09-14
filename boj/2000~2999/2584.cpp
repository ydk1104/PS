#include<stdio.h>
#include<vector>
#include<algorithm>

struct P{
	int x;
	int y;
	int cost;
	bool operator <(const P &x){
		return this->cost < x.cost;
	}
};

std::vector<int> edge[1001];
std::vector<P> v;
std::vector<int> a[2];

void dfs(int now, int check, int prev){
	a[check].push_back(now);
	for(auto i:edge[now]){
		if(i != prev ) dfs(i, 1-check, now);
	}
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<N; i++){
		int x, y, cost;
		scanf("%d %d %d", &x, &y, &cost);
		v.push_back({x, y, cost});
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	sort(v.begin(), v.end());
	dfs(1, 0, -1);
	for(auto i:a[0]) printf("%d ",i);
	int tocheck = 0;
	if(a[0].size() < M){
	}
	else tocheck = 1;
	int check[1001] = {0, };
	int anscost=0;
	for(auto i:a[tocheck]) check[i]++;
	for(auto i:v){
		if(check[i.x] ^ check[i.y]){
			anscost += i.cost;
			if(check[i.x]) a[tocheck].push_back(i.x);
			else a[tocheck].push_back(i.y);
			check[i.x]++;
			check[i.y]++;
		}
	}
	printf("%d\n", anscost);
	for(auto i:a[tocheck]) printf("%d ",i);
}
