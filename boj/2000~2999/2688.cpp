#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	long long dp[66][10] = {1, };
	for(int i=1; i<=65; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<=j; k++){
				dp[i][j] += dp[i-1][k];
			}
		}
	}
	while(T--){
		int N;
		scanf("%d", &N);
		printf("%lld\n", dp[N+1][9]);
	}
}
