#include<stdio.h>
#include<vector>

int cnt[200001];
int pa[200001];

int find(int x){
	return pa[x]<=0 ? x : pa[x] = find(pa[x]);
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	std::vector<std::pair<int, int> > edge;
	while(M--){
		int x,y;
		scanf("%d %d", &x, &y);
		edge.push_back({x,y});
		cnt[x]++; cnt[y]++;
	}
	int ans = 0;
	for(int i=1; i<=N; i++){
		if(!cnt[i]) ans-=2;
		else ans += cnt[i] = cnt[i]&1;
	}
	ans /= 2;
	int V = N;
	for(const auto& i : edge){
		int x = find(i.first), y = find(i.second);
		if(x==y) continue;
		V--;
		pa[x] |= pa[y] | -cnt[y];
		pa[y] = x;
	}
	ans += V;
	for(int i=1; i<=N; i++){
		if(pa[i] | -cnt[i] == -1) ans--;
	}
	printf("%d", ans);
}
