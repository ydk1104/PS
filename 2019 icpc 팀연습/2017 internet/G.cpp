#include<stdio.h>
#include<algorithm>
#include<tuple>

std::vector<std::pair<int,int> > v;

int p[10001],w[10001];
int dp[10001][10001];
int INF = 2e9;

int main(void){
	int N;
	scanf("%d", &N);
	v.resize(N);
	for(int i=0; i<N; i++){
		scanf("%d", &v[i].first);
	}
	for(int i=0; i<=N; i++){
		for(int j=0; j<=N; j++){
			dp[i][j] = INF;
		}
	}
	for(int i=0; i<N; i++){
		scanf("%d", &v[i].second);
	}
	sort(v.begin(), v.end()); /* , [](std::pair<int, int> x, std::pair<int, int> y){
		return x.first < y.first;
	}); // */
	for(int i=0; i<N; i++){
		p[i] = v[i].first;
		w[i] = v[i].second;
	}
	dp[0][0] = -2e9;
	int ans=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<=i; j++){
			if(i==N-1){
//				printf("-----\n");
			}
			if(dp[i][j] <= p[i]) dp[i+1][j+1] = std::min(dp[i+1][j+1], std::max(p[i], dp[i][j]+w[i]));
			dp[i+1][j] = std::min({dp[i+1][j], dp[i][j]+w[i]});
//			printf("dp[%d][%d] : %d ", i, j, dp[i][j]);
			if(dp[i+1][j+1]!=INF) ans = std::max(ans, j+1);
			if(dp[i+1][j]!=INF) ans =std::max(ans,j);
			if(dp[i][j]!=INF) ans=std::max(ans,j);
		}
//		printf("\n");
	}
	printf("%d",N-ans);
}
