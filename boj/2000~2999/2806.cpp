#include<stdio.h>
#define min(a,b) ((a)>(b)?(b):(a))

char s[1000001];
int N, ans[2];
int dp[1000001][2];

int main(void){
	scanf("%d\n%s", &N, s);
	dp[0][1-s[0]+'A']++;
	for(int i=1; s[i]; i++){
		if(s[i]=='A'){
			dp[i][0] = min(dp[i-1][0], dp[i-1][1]+1);
			dp[i][1] = min(dp[i-1][0]+1, dp[i-1][1]+1);
		}
		else{
			dp[i][0] = min(dp[i-1][0]+1, dp[i-1][1]+1);
			dp[i][1] = min(dp[i-1][0]+1, dp[i-1][1]);
		}
	}
	printf("%d", dp[N-1][0]);
}
