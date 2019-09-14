#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for(; T>0; T--){
		int N;
		scanf("%d", &N);
		int coin[22];
		for(int i=0; i<N; i++){
			scanf("%d", &coin[i]);
		}
		int tar;
		scanf("%d", &tar);
		int dp[10001]= {1, };
		for(int i=0; i<N; i++){
			for(int j=0; j+coin[i]<=tar; j++){
				dp[j+coin[i]] += dp[j];
			}
		}
		printf("%d\n", dp[tar]);
	}
}
