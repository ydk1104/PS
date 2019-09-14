#include<stdio.h>

int dp[1001][1001];

int nCr(int n, int r){
	if (dp[n][r]>0) return dp[n][r];
	if(r==n || r==0) return 1;
	if(r==n-1 || r==1) return n;
	dp[n][r] = nCr(n-1,r-1) + nCr(n-1,r);
	dp[n][r] %= 10007;
	return dp[n][r]; 
}

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d", nCr(N,K));
}
