#include<stdio.h>

int sum[100001];
int sum2[100001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int prev, x;
	for(int i=0; i<M; i++){
		int x;
		scanf("%d", &x);
		if(i){
			if(x>prev) sum[x]--, sum[prev]++;
			else sum[prev]--, sum[x]++;
		}
		prev=x;
	}
	for(int i=1; i<=N; i++) sum2[i] = sum2[i-1] + sum[i-1];
	long long ans=0;
	for(int i=1; i<N; i++){
		long long a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		ans += (a*sum2[i+1] < (b*sum2[i+1] + c)) ? a*sum2[i+1] : (b*sum2[i+1]+c);
	}
	printf("%lld",ans);
}
