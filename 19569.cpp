#include<stdio.h>

bool dp[100001][1001];
int ans[100001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		dp[i][0] = true;
		for(int j=0, sum=0; sum<i; j++, sum+=j){
			dp[i][j] = true;
		}
	}
	for(int i=0; i<N; i++){
		printf("%d %s\n", dp[i], dp[i] ? "¼±" : "ÈÄ");
	}
}
