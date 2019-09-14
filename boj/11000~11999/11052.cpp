#include<stdio.h>

int max(int a, int b){
	if (a>b) return a;
	return b;
}

int main(void){
	int N;
	scanf("%d", &N);
	int P[1001];
	int dp[1001] = {0,};
	for (int i=1; i<=N; i++){
		scanf("%d", &P[i]);
		for (int j=1; j<=i; j++){
			dp[i] = max(dp[i], dp[i-j] + P[j]);
		}
	}
	printf("%d", dp[N]);
}
