#include<stdio.h>

int map[52];
int dp[52][2];

int main(void){
	int N; 
	scanf("%d", &N);
	int M;
	scanf("%d", &M);
	for(int i=1; i<=M; i++){
		int temp;
		scanf("%d", &temp);
		map[temp] = 1;
	}
	dp[0][0] = 1;
	for(int i=1; i<=N; i++){
		if(map[i] == 1){
			dp[i][0] = dp[i-1][0];
		}
		else{
			dp[i][0] = dp[i-1][0] + dp[i-1][1];
			dp[i][1] = dp[i-1][0];
		}
	}
	printf("%d", dp[N][0]);
}
