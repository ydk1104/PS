#include<stdio.h>

int main(void){
	char P[111];
	char s[111];
	scanf("%s", &P);
	int plen = 0;
	while(P[plen]) plen++;
	int N;
	scanf("%d", &N);
	while(N--){
		getchar();
		scanf("%s", &s);
		int slen=0;
		while(s[slen]) slen++;
		int dp[111][111] = {1,};
		for(int i=0; i<=plen; i++){
			for(int j=0; j<=slen; j++){
//				printf("%d %d %d\n", i, j, dp[i][j]);
				if(P[i]==s[j]&&dp[i][j]) dp[i+1][j+1]=1;
				if(P[i]=='*'&&dp[i][j]) dp[i+1][j+1]=dp[i][j]=dp[i+1][j]=dp[i][j+1]=dp[i][j];
			}
		}
		if(dp[plen][slen])printf("%s\n", s);
	}
}
