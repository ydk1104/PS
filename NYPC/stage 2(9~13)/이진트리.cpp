#include<stdio.h>
#define INT_MAX 1000000007

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	long long int dp[501][501] = {0, };
	dp[0][0] = 0;
	for(int i=1; i<=K; i++) dp[1][i] = 1;
	for(int i=2; i<=N; i++){
		for(int j=2; j<=i; j++){
			if(dp[i][j-1]<0){
				printf("ERROR\n");
				return 0;
			}
			dp[i][j] = dp[i][j-1];
			long long int temp = dp[i-1][j-1] - dp[i-1][j-2];
			if(temp<0) temp += INT_MAX;
			dp[i][j] += (temp)*2;
			for(int k=1; k<(i-1); k++){
				temp = dp[k][j-1] - dp[k][j-2];
				if(temp<0) temp += INT_MAX;
				dp[i][j] += (dp[i-k-1][j-2] * temp)%INT_MAX;
				temp = dp[i-k-1][j-1] - dp[i-k-1][j-2];
				if(temp<0) temp += INT_MAX;
				dp[i][j] += (temp * dp[k][j-1])%INT_MAX;
				dp[i][j] %= INT_MAX;
			}
//			printf("dp[%d][%d] = %lld\n",i, j, dp[i][j]);
			dp[i][j] %= INT_MAX;
		}
		for(int j=i+1; j<=K; j++) dp[i][j] = dp[i][j-1];
	}
	long long int ans = dp[N][K];
	if(K>0) ans -= dp[N][K-1];
	if(ans<0) ans+=INT_MAX;
	printf("%lld", ans);
}
