#include<stdio.h>

int main(void){
	int N, K;
	 scanf("%d %d", &N, &K);
	int DP[201][201] = {0, };
	DP[0][0] = 1;
	for(int i=0; i<=N; i++){
		for(int j=1; j<=K; j++){
			for(int k=0; k<=i; k++){
				DP[i][j] = DP[i][j] + DP[i-k][j-1];
				DP[i][j] %= 1000000000;
			}
		}
	}
	printf("%d", DP[N][K]);
}
