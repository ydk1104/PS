#include<stdio.h>
#define min(a,b) ((a)>(b) ? (b) : (a))

int dp[201][201];

int main(void){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	dp[0][0] = 1;
	for(int i=1; i<=N+M; i++){
		dp[i][0] = 1;
		for(int j=1; j<=i; j++){
			dp[i][j] = min(dp[i-1][j-1]+dp[i-1][j], 1000000000);	
		}
	}
	if(K>dp[N+M][M]) printf("-1");
	else{
		int max = N+M;
		for(int i=1; i<=max; i++){
			if(K>dp[N+M-1][M]){
				K -= dp[N+M-1][M];
				M--;
				printf("z");
			}
			else{
				N--;
				printf("a");
			}
		}
	}
}

//http://codersbrunch.blogspot.com/2016/01/1256.html
