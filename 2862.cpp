#include<stdio.h>

long long dp[101] = {1,1};

long long func(long long N){
	int i=1;
	for(; dp[i]<=N; i++){
		dp[i+1] = dp[i] + dp[i-1];
	}
	if(dp[i]==N) return N;
	return func(N-dp[i-1]);
}

int main(void){
	long long N;
	scanf("%lld", &N);
	printf("%lld", func(N));
}
