#include<stdio.h>

int min(int a, int b){
	if (a==0) return b;
	if (a<b) return a;
	return b;
}

int main(void){
	int N;
	scanf("%d", &N);
	int dp[100001] = {0, };
	for (int i=1; i*i<=N; i++){
		for (int j=0; j+i*i<=N; j++){
			dp[j+i*i] = min(dp[j+i*i], dp[j]+1);
		}
	}
	printf("%d", dp[N]);
}
