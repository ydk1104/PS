#include<stdio.h>
#include<string.h>

int main(void){
	char N[5002];
	int dp[5003] = {1, };
	scanf("%s", N+1);
	int s = strlen(N+1);
	int i, a;
	for(i=1; i<=s; i++){
		if(N[i]>'0'){
			dp[i] = dp[i-1] % 1000000;
		}
		if(i>1) {
			a = (N[i-1] - '0') * 10 + N[i] - '0';
			if(a>=10 && a<=26){
				dp[i] = (dp[i] + dp[i-2]) % 1000000;
			}
		}
	}
	printf("%d\n", dp[s]);
}
