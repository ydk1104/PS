#include<stdio.h>

int max(int a, int b, int c){
	if (a>b && a>c) return a;
	if (b>c) return b;
	return c;
}

int main(void){
	int N;
	scanf("%d", &N);
	int a[10001];
	int dp[10001][3] = {0, };
	for (int i=1; i<=N; i++){
		scanf("%d", &a[i]);
		dp[i][0] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
		dp[i][1] = dp[i-1][0] + a[i];
		dp[i][2] = dp[i-1][1] + a[i];
	}
	printf("%d", max(dp[N][0], dp[N][1], dp[N][2]));
}
