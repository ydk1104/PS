#include<stdio.h>
#include<algorithm>

int N;
int Exp[15][15];
int dp[65536];

int func(int now){
	if(~dp[now]) return dp[now];
	int plus = 0;
	for(int i=0; i<N; i++){
		if(now & 1<<i) continue;
		int temp = func(now | 1<<i);
		for(int j=0; j<N; j++) if(now & 1<<j) temp += Exp[i][j];
		plus = std::max(plus, temp);
	}
	return dp[now] = plus;
}

int main(void){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &Exp[i][j]);
		}
	}
	for(int i=0; i<=1<<N; i++) dp[i] = -1;
	int ans=0;
	for(int i=0; i<N; i++){
		ans = std::max(ans, func(1<<i));
	}
	printf("%d", ans);
}
