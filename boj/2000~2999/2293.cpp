#include<stdio.h>

int main(void){
	int n, k;
	scanf("%d %d", &n, &k);
	int coin;
	int dp[10001][2] = {1, };
	int ox = 0;
	for (int i=1; i<=n; i++){
		scanf("%d", &coin);
		for (int j=0; j<=k; j++){
			dp[j][1-ox] = 0;
			for (int l=0; l*coin<=j; l++){
				dp[j][1-ox] += dp[j-l*coin][ox];
			}
		}
		ox = 1-ox;
	}
	printf("%d", dp[k][ox]);
}
