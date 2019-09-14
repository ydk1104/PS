#include<stdio.h>

int dp[15][15];

int find(int a, int b){
	if(dp[a][b] > 0){
		return dp[a][b];
	}
	if(a==0){
		dp[a][b] = b;
		return b;
	}
	for(int i=1; i<=b; i++){
		dp[a][b] += find(a-1, i);
	}
	return dp[a][b];
}

int main(void){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int N, K;
		scanf("%d %d", &N, &K);
		printf("%d\n", find(N, K));
	}
}
