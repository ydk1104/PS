#include<stdio.h>
#include<algorithm>

int a[200001];
int dp[200001];
int sum[200011];

int main(void){
	int T;
	for(scanf("%d", &T); T--;){
		int N,P,K;
		scanf("%d %d %d", &N, &P, &K);
		for(int i=0; i<N; i++) scanf("%d", a+i), dp[i] = 0;
		std::sort(a, a+N);
		int ans = 0;
		for(int i=0; i<K; i++){
			dp[i+1] = sum[i+1] = sum[i] + a[i]; // i+1개를 사는데 드는 비용 
			if(dp[i+1] <= P) ans = i+1;
		}
		for(int i=K-1; i<N; i++){
			dp[i+1] = std::min(dp[i]+a[i], dp[i-K+1]+a[i]);
//			sum[i+2] = dp[i] + a[i+1];
			if(dp[i+1] <= P) ans = i+1;
		}
		printf("%d\n", ans);
		printf("test start");
		printf("\na : ");
		for(int i=0; i<N; i++){
			printf("%d ", a[i]);
		}
		printf("\nsum : ");
		for(int i=0; i<=N; i++){
			printf("%d ", sum[i]);
		}
		printf("\ndp : ");
		for(int i=0; i<=N; i++){
			printf("%d ", dp[i]);
		}
		printf("\n\n");
	}
}
