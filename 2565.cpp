#include<stdio.h>

int arr[501], dp[501];

int main(void){
	int N;
	scanf("%d", &N);
	int ans=0;
	for(int i=0; i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x] = y;
	}
	for(int i=0; i<501; i++){
		if(!arr[i]) continue; 
		int max=0;
		for(int j=0; j<arr[i]; j++){
			if(dp[j] > max) max = dp[j];
		}
		dp[arr[i]] = max+1;
		if(dp[arr[i]] > ans) ans = dp[arr[i]];

	}
	printf("%d", N-ans);
}
