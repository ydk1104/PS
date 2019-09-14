#include<stdio.h>

int dp[2001][2001];
int num[2001] = {0, };

int check(int a, int b){
	if(dp[a][b] != -1){
		return dp[a][b];
	}
	if(b-a<2){
		if(num[a] == num[b]){
			dp[a][b] = 1;
		}
		else{
			dp[a][b] = 0;
		}
		return dp[a][b];
	}
	else{
		if(num[a] != num[b]){
			dp[a][b] = 0;
			return dp[a][b];
		}
		dp[a][b] = check(a+1, b-1);
		return dp[a][b];
	}
}

int main(void){
	int N, M;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &num[i]);
		for(int j=1; j<=N; j++){
			dp[i][j] = -1;
		}
	}
	scanf("%d", &M);
	for(int i=1; i<=M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", check(a, b));
	}
}
