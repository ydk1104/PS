#include<stdio.h>

char s[30];
const int mod = 1e9+7;
//char 
	long long dp[1000010][6] = {0, };
	int o[1000010][6] = {0, };

int main(void){
	int N;
	scanf("%d", &N);
	char A[6] = "UNIST";
	dp[0][0] = 1;
	for(int i=1; i<=N; i++){
		int o[6][6] = {0, };
		scanf("%s", &s);
		for(int j=0; j<6; j++){
			o[j][j] = 1;
			for(int k=j+1; k<6; k++){
				o[j][k] = o[j][k-1] && (s[k-j-1] == A[k-1]);
			}
			for(int k=j; k>=0; k--){
				dp[i][j] += dp[i-1][k] * o[k][j];
				dp[i][j] %= mod;
//				printf("%d %d %d : %d %d %d\n", i, j, k, dp[i][j], dp[i-1][k], o[k][j]);
			}
		}
	}
	
	printf("%d", dp[N][5]);
}
