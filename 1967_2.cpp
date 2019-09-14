#include<stdio.h>
#include<vector>
#include<tuple>

std::vector<std::pair<int, int> >edge[10001];
int max, ans;

void dfs(int now, int sum, int prev){
	int check=0;
	for(auto i:edge[now]){
		if(prev != i.first){
			dfs(i.first, sum+i.second, now);
			check=1;
		}
	}
	if(!check){
		if(sum > max) ans = now, max = sum;
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		edge[x].push_back({y,z});
		edge[y].push_back({x,z});
	}
	dfs(1, 0, 0);
	dfs(ans, 0, 0);
	printf("%d", max);
}
