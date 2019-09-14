#include<stdio.h>

int max(int a, int b){
	if (a>b) return a;
	return b;
}

int main(void){
	int N;
	int a[100001];
	int dp[100001][2] = {0, };
	int maxN = -1001;
	scanf("%d", &N);
	for (int i=1; i<=N; i++){
		scanf("%d", &a[i]);
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		dp[i][1] = max(dp[i-1][1]+a[i],+a[i]);
		maxN = max(maxN, a[i]);
	}
	if(maxN<0){
		printf("%d", maxN);
		return 0;
	}
	printf("%d", max(dp[N][0], dp[N][1]));
	return 0;
}
