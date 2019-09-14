#include<stdio.h>

int min(int a, int b){
	if (a==-1) return b;
	if (a>b) return b;
	return a;
}

int main(void){
	int n, k;
	scanf("%d %d", &n, &k);
	int coin[101];
	int dp[10001];
	for (int i=1; i<=k; i++){
		dp[i] = -1;
	}
	for (int i=1; i<=n; i++){
		scanf("%d", &coin[i]);
		if (coin[i]>k) coin[i] = 0;
		dp[coin[i]] = 1;
	}
	for (int i=1; i<=k-1; i++){
		if (dp[i] != -1){
		for (int j=1; j<=n; j++){
				if(i+coin[j] <= k){
					dp[i+coin[j]] = min(dp[i+coin[j]], dp[i]+1);
				}
			}
		}
	}
	printf("%d", dp[k]);
}
