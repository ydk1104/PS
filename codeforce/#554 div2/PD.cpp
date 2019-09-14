#include<stdio.h>
#define MOD(x) x%=1000000007
#define max(a,b) ((a)>(b)?(a):(b))

int dp[2001][2001][2];
int N;

int func(int now, int left, int check){
	if(left>N/2) return 0-check;
	if(now>left*2) return 0-check;
	if(dp[now][left][check]) return dp[now][left][check];
	if(now==N) return dp[now][left][check]=0;
	dp[now][left][check] = func(now+1, left, 0) + func(now+1, left+1, 0);
	if(!check) dp[now][left][check] = max(dp[now][left][check], 1+func(now+1,left,1)+func(now+1,left+1,0));
	if(!check) dp[now][left][check] = max(dp[now][left][check], 1+func(now+1, left, 0)+func(now+1, left+1, 1));
	MOD(dp[now][left][check]);
	return dp[now][left][check];
}

int main(void){
	scanf("%d", &N);
	N*=2;
	printf("%d", func(0, 0, 0));
}
