#include<stdio.h>

int dp[100] = {0, };

int fi(int N){
	if(N == 0){
		return 0;
	}
	if(N == 1){
		return 1;
	}
	if(dp[N] > 0){
		return dp[N];
	}
	else{
		dp[N] = fi(N-1) + fi(N-2);
		return dp[N];
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	printf("%d", fi(N));
}
