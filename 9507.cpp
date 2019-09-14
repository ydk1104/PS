#include<stdio.h>

long long int dp[100] = {1, 1, 2, 4, };

long long int fi(int N){
	if(dp[N] > 0){
		return dp[N];
	}
	else{
		dp[N] = fi(N-1) + fi(N-2) + fi(N-3) + fi(N-4);
		return dp[N];
	}
}

int main(void){
	int T, n;
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
		scanf("%d", &n);
		printf("%lld\n", fi(n));
	}
	return 0;
}
