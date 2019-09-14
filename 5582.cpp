#include<stdio.h>
#include<algorithm>

char a[4001], b[4001];
int dp[4010][4010], ans;

int main(void){
	scanf("%s %s", a, b);
	for(int i=0; a[i]; i++){
		for(int j=0; b[j]; j++){
			if(a[i]==b[j]) dp[i+1][j+1] = std::max(dp[i+1][j+1], dp[i][j]+1), ans = std::max(ans, dp[i+1][j+1]);
		}
	}
	printf("%d", ans);
}
