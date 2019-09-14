#include<stdio.h>

long long int dp[501][501];
int page[501];
int sumpage[501][501];

int min(int a, int b){
	if(a>b) return b;
	return a;
}

int sum(int a, int b){
	if(sumpage[a][b] > 0){
		return sumpage[a][b];
	}
	for(int i=a; i<=b; i++){
		sumpage[a][b] += page[i];
	}
	return sumpage[a][b];
}

long long int plus(int start, int end){
	if(dp[start][end] >= 0){
		return dp[start][end];
	}
	int a = plus(start+1, end);
	for(int i=start+1; i<=end-1; i++){
		a = min(a, plus(start, i)+plus(i+1, end));
	}
	a += sum(start, end);
	dp[start][end] = a;
	return a;
}

int main(void){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int k;
		scanf("%d", &k);
		for(int i=1; i<=k; i++){
			scanf("%d", &page[i]);
			for(int j=1; j<=k; j++){
				dp[i][j] = -1;
				sumpage[i][j] = 0;
			}
			dp[i][i] = 0;
			sumpage[i][i] = page[i];
		}
		printf("%lld\n", plus(1,k));
	}
}
