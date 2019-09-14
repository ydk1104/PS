#include<stdio.h>
#define MAX 1000000

int dp[2*MAX+1] = {0, 1, 1, };

int main(void){
	long long N;
	scanf("%lld", &N);
	for(int i=2; i<=2*MAX; i++){
		dp[i] = dp[i-1] + dp[i-2];
		dp[i] %= MAX;
	}
	printf("%d", dp[N%1500000]);
}
