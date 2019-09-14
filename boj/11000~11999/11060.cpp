#include<stdio.h>
#define min(a,b) (((a<b)&&(a!=0)) ? (a) : (b))

int main(void){
	int N;
	int map[1001];
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &map[i]);
	}
	int dp[1001] = {0, };
	dp[1] = 1;
	for(int i=1; i<=N; i++){
		if(dp[i] != 0){
			for(int j=1; j<=map[i]; j++){
				if(i+j>N) break;
				dp[i+j] = min(dp[i+j], dp[i]+1);				
			}
		}
	}
	printf("%d", dp[N]-1);
}
