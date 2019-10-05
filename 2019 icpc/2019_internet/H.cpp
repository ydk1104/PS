#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<int> v;

int dp[100001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i*i<=N; i++){
		v.push_back(i*i);
	}
	for(int i=1; i<=N; i++) dp[i] = 5;
	for(int i=0; i<=N; i++){
		for(auto j:v){
			dp[i+j] = std::min(dp[i+j], dp[i]+1);
		}
	}
	printf("%d", dp[N]);
}
