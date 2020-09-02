#include<stdio.h>
#include<algorithm>

int value[1001], t[1001];
int dp[10001];

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=0; i<K; ++i){
		scanf("%d %d", &value[i], &t[i]);
	}
	for(int j=0; j<K; ++j){
		for(int i=N; i>=t[j]; --i){
			dp[i] = std::max(dp[i], dp[i-t[j]]+value[j]);
		}
	}
	printf("%d", *std::max_element(dp, dp+N+1));
}
