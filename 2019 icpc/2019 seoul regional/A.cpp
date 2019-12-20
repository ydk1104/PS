#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int dp[1001] = {1, 1, };
	for(int i=2; i<=N; i++){
		int check[1001] = {0, };
		for(int j=1; j*2<=i; j++){
			check[dp[i-j]*2-dp[i-2*j]]++;
		}
		int now=1;
		while(check[now]) now++;
		dp[i] = now;
	}
	printf("%d", dp[N]);
}
