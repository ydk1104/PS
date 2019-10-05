#include<stdio.h>
#include<algorithm>

long long a[100001], p[100001], w[100001], dp[100001];
long long ans = 1e18;
long long sum[100001], min[100001], now;

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<=N; i++) dp[i] = 1e18;
	for(int i=0; i<N-1; i++){
		scanf("%lld", &a[i]);
		sum[i+1] = sum[i] + a[i];
	}
	for(int i=0; i<N-1; i++){
		scanf("%lld %lld", &p[i], &w[i]);
		if(!i) min[i] = w[i];
		else min[i] = std::min(min[i-1], w[i]);
	}
	dp[0] = 0;
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			dp[j] = std::min(dp[j], dp[i] + p[i] + w[i] * (sum[j] - sum[i]));
		}
	}
	for(int i=0; i<N; i++){
		printf("%d\n", dp[i]);
	}
}
/*
5
5 10 4 8
3 6
8 3
4 8
15 4

*/
