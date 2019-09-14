#include<stdio.h>

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int max3(int a, int b, int c){
	if(a>b && a>c) return a;
	if(b>c) return b;
	return c;
}

int min(int a, int b){
	if(a>b) return b;
	return a;
}

int min3(int a, int b, int c){
	if(a<b && a<c){
		return a;
	}
	if(b<c) return b;
	return c;
}
	int dp[2][3] = {0, };
	int dp2[2][3] = {0, };

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dp[i%2][0] = max(dp[1-i%2][0], dp[1-i%2][1])+a;
		dp[i%2][1] = max3(dp[1-i%2][0], dp[1-i%2][1], dp[1-i%2][2])+b;
		dp[i%2][2] = max(dp[1-i%2][1], dp[1-i%2][2])+c;
		dp2[i%2][0] = min(dp2[1-i%2][0], dp2[1-i%2][1])+a;
		dp2[i%2][1] = min3(dp2[1-i%2][0], dp2[1-i%2][1], dp2[1-i%2][2])+b;
		dp2[i%2][2] = min(dp2[1-i%2][1], dp2[1-i%2][2])+c;
	}
	printf("%d %d", max3(dp[N%2][0], dp[N%2][1], dp[N%2][2]), min3(dp2[N%2][0], dp2[N%2][1], dp2[N%2][2]));
}
