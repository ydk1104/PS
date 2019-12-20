#include<stdio.h>
#include<vector>
#include<algorithm>
 
long long sum[100001];
 
int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int x,y; long long cost;
		scanf("%d %d %lld", &x, &y, &cost);
		x--; y--;
		sum[x] += cost; sum[y] -= cost;
	}
	struct xyz{
		int x,y; long long z;
		void print()const{printf("%d %d %lld\n", x,y,z);}
	};
	std::vector<xyz> ans;
	
	std::vector<int> v[2];
	for(int i=0; i<N; i++){
		if(!sum[i]) continue;
		v[sum[i]>0].push_back(i);
	}
	for(int i=0,j=0; i<v[0].size()&&j<v[1].size();){
		int x=v[0][i], y=v[1][j];
		long long min = std::min(-sum[x], sum[y]);
		sum[x] += min;
		sum[y] -= min;
		ans.push_back({y+1,x+1,min});
		i+=!sum[x]; j+=!sum[y];
	}
	printf("%d\n", ans.size());
	for(const auto& i : ans){
		i.print();
	}
}
