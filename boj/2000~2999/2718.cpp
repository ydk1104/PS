#include<stdio.h>

int dp[102] = {0, 1, 1, };

int main(void){
	int T;
	scanf("%d", &T);
	for(int i=3; i<=101; i++) dp[i] = dp[i-1] + 4*dp[i-2] + 2*dp[i-3];
	while(T--){
		int N;
		scanf("%d", &N);
		printf("%d\n", dp[N+1]);
	}
}
