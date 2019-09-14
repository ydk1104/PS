#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))

int N, M, a[1000001];
int dp[1000001][3][3];

int min3(int a, int b, int c){
	if(a<b && a<c) return a;
	if(b<c) return b;
	return c;
}

void update(int i, int j, int k){
	if(k>a[i]){
		dp[i][j][k] = -1000;
		return;
	}
	if(i==1 && (j!=0 || k!=0)) return;
	if(i==2 && j!=0) return;
	int plus = -1000;
	for(int l=0; l<3; l++){
		int temp = dp[i-1][l][j];
		plus = max(temp, plus);
	}
	if(plus == -1000){
		dp[i][j][k] = -1000;
		return;
	}
	int T = a[i]-k;
	dp[i][j][k] = plus + T/3;
	if(i<=2) return;
	if(j==0){
		int temp = 1;
		if(T%3 >= 2) temp++;
//		dp[i][j][k] = max(dp[i][j][k], dp[i-1][2][j+2]+temp);
	}
	if(j<=1){
		int temp = 0;
		if(T%3 >= 1) temp++;
		dp[i][j][k] = max(dp[i][j][k], dp[i-1][1][j+1]+temp);
//		dp[i][j][k] = max(dp[i][j][k], dp[i-1][2][j+1]+temp);
	}
	return;
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	for(int i=1; i<=M; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				update(i, j, k);
//				printf("%d %d %d %d\n", i, j, k, dp[i][j][k]);
			}
		}
	}
	int ans = 0;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			ans = max(ans, dp[M][i][j]);
		}
	}
	printf("%d", ans);
}
