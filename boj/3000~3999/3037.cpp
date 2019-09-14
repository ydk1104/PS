#include<stdio.h>
#define mod 1000000007
#define MOD(x) (x)%=mod

int dp[1001][10001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	dp[0][0] = 1;
	for(int i=1; i<=N; i++){
		for(int j=0; j<=M && j<=(i*(i-1))/2; j++){
			dp[i][j] = dp[i-1][j];
			if(j>0) dp[i][j] += dp[i][j-1];
			if(j>=i) dp[i][j] -= dp[i-1][j-i];
			MOD(dp[i][j]);
			if(dp[i][j]<0){dp[i][j] += mod;}
		}
	}
	printf("%d", dp[N][M]);
}
