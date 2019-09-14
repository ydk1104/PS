#include<stdio.h>

int dp[205][205], debug=0;

void func(int sum, int a, int K, char type){
	if(!K) return;
	if(sum==a){for(int i=0; i<sum; i++) printf("a"); return;}
	if(!a){for(int i=0; i<sum; i++) printf("z"); return;}
	if(type=='a'){
		if(debug) printf("\n%d %d %d ", sum, a, K);
		if(dp[sum-1][a-1] >= K) printf("a"), a--;
		else printf("z"), K-=dp[sum-1][a-1];
		func(sum-1, a, K, type);
	}
}

int main(void){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	v:
	for(int i=0; i<=N+M; i++){
		dp[i][0] = 1;
		for(int j=1; j<=N+M; j++){
			dp[i+1][j] = dp[i][j] + dp[i][j-1];
			if(dp[i+1][j] >= 1000000000) dp[i+1][j] = 1000000000;
			if(debug) printf("%d ", dp[i+1][j]);
		}
		if(debug) printf("\n");
	}
	if(dp[N+M][N] < K){
		printf("-1");
		return 0;
	}
	func(N+M, N, K, 'a');
}
