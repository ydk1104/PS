#include<stdio.h>
#define min(a,b) (((a)<(b))&&((a)!=0) ? (a) : (b))

int tri[300000];
int four[300000];
int dp[300001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; tri[i-1]<=N; i++){
		tri[i] = tri[i-1] + i;
	}
	for(int i=1; four[i-1]<=N; i++){
		four[i] = four[i-1] + tri[i];
	}
	for(int i=0; i<=N; i++){
		for(int j=1; i+four[j]<=N; j++){
			dp[i+four[j]] = min(dp[i+four[j]], dp[i]+1);
		}
	}
	printf("%d", dp[N]);
}
