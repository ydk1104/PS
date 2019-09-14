#include<stdio.h>

int max(int a, int b){
	if (a>b) return a;
	return b;
}

int main(void){
	int N;
	scanf("%d", &N);
	int a[1001];
	int dp[1001] = {0, };
	for (int i=1; i<=N; i++){
		scanf("%d", &a[i]);
		for (int j=1; j<i; j++){
			if(a[i] > a[j]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	int ans = 0;
	for (int i=1; i<=N; i++){
		ans = max(ans, dp[i]);
	}
	printf("%d", ans+1);
	return 0;
}
