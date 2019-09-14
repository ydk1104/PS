#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

int a[1001];
int dp[1001][1001];
int back[1001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	for(int i=0; i<N; i++){
		int Max=0, prev=-1;
		for(int j=0; j<i; j++){
			if(i) dp[i][j] = dp[i-1][j];
			if(i && a[i]>a[j] && Max<dp[i][j]) Max = dp[i][j], prev=j;
		}
		dp[i][i] = Max+1;
		back[i] = prev;
	}
	int Max=0;
	int ans[1001] = {0, };
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
//			printf("%d ",dp[i][j]);
		}
//		printf("\n");
	}
	for(int i=0; i<N; i++) Max<dp[N-1][i]?Max=dp[N-1][i],ans[0]=i:1;
	printf("%d\n",Max);
//	for(int i=1; i<N; i++) ans[i] = back[ans[i-1]];
//	for(int i=N-1; i>0; i--) printf("%d ",ans[i]);
	int cnt=Max;
	for(int i=N-1; i>=0; i--) if(dp[N-1][i] == cnt) ans[cnt]=a[i], cnt--;
	for(int i=0; i<Max; i++) printf("%d ",ans[i+1]);
}
