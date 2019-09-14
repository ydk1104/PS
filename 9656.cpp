#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int dp[1001] = {0, 0, 1, 0, 1, };
	for(int i=5; i<=N; i++){
		if(dp[i-1] && dp[i-3] && dp[i-4]) dp[i] = 0;
		else dp[i] = 1;
	}
	if(dp[N]) printf("SK");
	else printf("CY");
}
