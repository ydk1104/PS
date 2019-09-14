#include<stdio.h>

int main(void){
	int N, M;
	int a[301][301];
	int dp[301][301] = {0, };
	scanf("%d %d", &N, &M);
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			scanf("%d", &a[i][j]);
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i][j];
		}
	}
	int k;
	scanf("%d", &k);
	for (int i=1; i<=k; i++){
		int aa, ab, ac, ad;
		scanf("%d %d %d %d", &aa, &ab, &ac, &ad);
		int sum = dp[ac][ad] - dp[ac][ab-1] - dp[aa-1][ad] + dp[aa-1][ab-1];
		printf("%d\n", sum);
	}
}
