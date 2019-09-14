#include<stdio.h>

int main(void){
	long long N, cnt=0;
	scanf("%lld", &N);
	int dp[21] = {0, };
	for(int i=1; i<=20; i++){
		int flag = 1;
		for(int j=1; j<=i; j*=4){
			flag *= dp[i-j];
		}
		dp[i] = !flag;
	}
	N %= 20;
	if(dp[N]) printf("SK");
	else printf("CY");
}
