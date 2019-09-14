#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

struct candy{
	int cost;
	int value;
};

candy a[5001];
int dp[20001];

int main(void){
	int N;
	double M;
	scanf("%d %lf", &N, &M);
	while(N!=0 && M!=0.00){
		int x;
		double y;
		for(int i=0; i<N; i++){
			scanf("%d %lf", &x, &y);
			a[i].value = x;
			a[i].cost = (int)(y*100);
		}
		int nowM = (int)(M*100);
		for(int i=0; i<=nowM; i++) dp[i]=0;
		for(int i=0; i<=nowM; i++){
			for(int j=0; j<N; j++){
				dp[i+a[j].cost] = max(dp[i+a[j].cost], dp[i]+a[j].value);
			}
		}
		printf("%d\n", dp[nowM]);
		scanf("%d %lf", &N, &M);
	}
}
