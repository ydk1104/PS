#include<stdio.h>

int dp[20][20];

int way(int N, int M, int n, int m, int cnt){
	if(N==n && M==m){
		return cnt;
	}
	if(N<n || M<m){
		return 0;
	}
	if(dp[N][M] != 0){
		return dp[N][M];
	}
	dp[N][M] = way(N-1, M, n, m, cnt) + way(N, M-1, n, m, cnt);
	cnt = dp[N][M];
	return cnt;
}

int main(void){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int a = (K-1)/M+1;
	int b = (K-1)%M+1;
	if(K==0){
		a = b = 1;
	}
	int ans = way(a, b, 1, 1, 1) * way(N, M, a, b, 1);
	printf("%d", ans);
}
