#include<stdio.h>
#define INF 100000000
#define min(a,b) ((a)<(b) ? (a) : (b))
#define min4(a,b,c,d) (min(min(a,b),min(c,d)))

int kcal[3001];
int dp[3001][3];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=3*N; i++){
		scanf("%d", &kcal[i]);
	}
	for(int i=1; i<=3*N; i++){
		dp[i][0] = min4(dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][2]);
		dp[i][0] += kcal[i];
		dp[i][1] = dp[i-1][0];
		dp[i][2] = dp[i-1][1];
	}
	printf("%d", min4(dp[3*N][0], dp[3*N][1], dp[3*N][2], dp[3*N][2]));
}
