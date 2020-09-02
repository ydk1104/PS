#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<std::pair<int,int> > v;

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		v.emplace_back(x,y);
	}
	int dp[100001] = {0, };
	for(const auto& i : v){
		int x = i.first, y = i.second;
		for(int j=K; j>=x; --j){
			dp[j] = std::max(dp[j], dp[j-x]+y);
		}
	}
	printf("%d\n", *std::max_element(dp, dp+K+1));
}
