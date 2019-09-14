#include<stdio.h>
#define max(a,b) (((a)>(b)) ? (a) : (b))

int N;
int a[2001];
int b[2001];
int dp[2002][2002];

int game(int left, int right){
	if((left>N) || (right>N)) return 0;
	if(dp[left][right] != -1) return dp[left][right];
	int ans1, ans2, ans3;
	ans1 = ans2 = ans3 = 0;
	if(a[left]>b[right]) ans3 = game(left, right+1)+b[right];
	ans2 = game(left+1, right+1);
	ans1 = game(left+1, right);
	ans1 = max(ans1, ans2);
	ans1 = max(ans1, ans3);
	return dp[left][right] = ans1;
} // */

int main(void){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=N; i++){
		scanf("%d", &b[i]);
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			dp[i][j] = -1;
		}
	}
/*	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(dp[j][i] != -1){
				if(a[j]>b[i]) dp[j][i+1] = max(dp[j][i+1], dp[j][i]+b[i]);
				dp[j+1][i+1] = max(dp[j+1][i+1], dp[j][i]);
				dp[j+1][i] = max(dp[j+1][i], dp[j][i]);				
			}
		}
	}
	int ans = 0;
	for(int i=1; i<=N+1; i++){
		ans = max(ans, dp[N+1][i]);
		ans = max(ans, dp[i][N+1]);
	}
	printf("%d", ans); // */
	int ans = game(1, 1);
	printf("%d", ans); // */
}
