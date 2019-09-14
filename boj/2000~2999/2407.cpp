#include<stdio.h>

long long int dp[101][101][1001];

void nCr(int n, int r){
	if(dp[n][r][0] == 0){ // 이미 구한 값인지 체크 
		return;
	}
	if(r==0){
		dp[n][r][1] = 1; // nC0 = 1
		dp[n][r][0] = 0; // 값을 구했다는 표시 
		return;
	}
	if(r==n){
		dp[n][r][1] = 1; // nCn == 1
		dp[n][r][0] = 0; // 값을 구했다는 표시 
		return;
	}
	nCr(n-1, r-1), nCr(n-1, r); // n-1Cr-1, n-1Cr의 값을 구하여 둘을 더할 것 
	for(int i=1; dp[n-1][r-1][i] + dp[n-1][r][i] != -2; i++){//값이 존재하는한 덧셈 
		if(dp[n][r][i] == -1){
			dp[n][r][i] ++;
		} // -1로 초기화해주었으니 0으로 만들기 위해 
		dp[n][r][i] += dp[n-1][r-1][i] + dp[n-1][r][i]; // 같은자리 덧셈 
		if(dp[n-1][r-1][i] == -1){ // 없는 값일 경우 덧셈취소 
			dp[n][r][i] ++;
		}
		if(dp[n-1][r][i] == -1){ // 없는 값일 경우 덧셈 취소 
			dp[n][r][i] ++;
		}
		if(dp[n][r][i]>9){ // 십진법을 사용 
			if(dp[n][r][i+1] == -1){ // 값이 없을경우 0으로 초기화 
				dp[n][r][i+1]++;
			}
			dp[n][r][i+1] += dp[n][r][i]/10; // 10을 넘어가면 다음자리로 넘김 
			dp[n][r][i] %= 10; // 다음자리로 넘기고 남은 값 
		}
	}
	dp[n][r][0] = 0; // nCr을 구했다는 표시 
	return;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<=N; i++){
		for(int j=0; j<=M; j++){
			for(int k=0; k<=1000; k++){
				dp[i][j][k] = -1; // 0이 포함될 수 있으므로 -1로 초기화 
			}
		}
	}
	nCr(N, M); // nCr의 값을 구하기 
	int i = 1;
	for(; dp[N][M][i] != -1; i++){
	} // nCr의 자릿수를 구하기 
	for(i--; i>0; i--){
		printf("%d", dp[N][M][i]);
	}
}
