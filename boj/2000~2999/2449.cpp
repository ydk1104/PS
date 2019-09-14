#include<stdio.h>

int N, K, a[201], dp[201][201];

int func(int left, int right){
	if(left>=right) return 0;
	if(~dp[left][right]) return dp[left][right];
	int tmp = right-left;
	for(int i=left; i<right; i++){
		int tmp2 = func(left, i) + func(i+1, right) + (a[left]!=a[i+1]);
		if(tmp>tmp2) tmp=tmp2;
	}
	return dp[left][right] = tmp;
}

int main(void){
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
		if(i && a[i]==a[i-1]) i--, N--;
	}
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) dp[i][j] = -1;
	printf("%d", func(0, N-1));
}
