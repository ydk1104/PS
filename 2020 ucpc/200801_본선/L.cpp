#include<stdio.h>

int a[2001];
int dp[1001][1001][101];
int N;

int solve(int l, int r, int t, int max, int turn){
	if(t<0){
		turn = 1-turn;
		t = -t;
	}
	if(t==0) turn = 0;
//	if(l > N) l = 1;
//	if(r <= 0) r = N;
	if(dp[l][r][t]){
		if(turn) return dp[l][r][t];
		else return max - dp[l][r][t];
	}
	if(l == r){
		if(turn) return a[l];
		else return max - a[l];
	}
	int x = max-solve(l+1, r, t-a[l], max-a[l], turn)+a[l];
	int y = max-solve(l, r-1, t-a[r], max-a[r], turn)+a[r];
	printf("lrxy : %d %d %d %d\n", l,r,x,y);
	if(x>y) y=x;
	if(turn) return dp[l][r][t] = y;
	else return max - (dp[l][r][t] = y);
}

int main(void){
	scanf("%d", &N);
	int max = 0;
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
		a[i+N] = a[i];
		max += a[i];
	}
	int ans = 0;
	for(int i=0; i<N; i++){
		int temp = max - solve(i+1, i+N-1, a[i], max-a[i], 0);
		if(temp > ans) ans = temp;
		printf("%d %d\n", i, temp);
	}
	printf("%d", ans);
}
