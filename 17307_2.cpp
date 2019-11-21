#include<stdio.h>
#include<algorithm>

int x[250001];
long long sum[250010][2];

int main(void){
	int N, C;
	scanf("%d %d", &N, &C);
	for(int i=1; i<=N; i++) scanf("%d", x+i);
	for(int i=1; i<N; i++) sum[i+1][0] = sum[i][0] + (x[i]-x[i+1]+C)%C;
	for(int i=N; i>1; i--) sum[i-1][1] = sum[i][1] + (x[i]-x[i-1]+C)%C;
	int ans=1;
	long long now_max = sum[1][0] + sum[1][1];
	for(int i=1; i<=N; i++){
		long long now = *std::max_element(sum[i], sum[i]+2);
		if(now < now_max) now_max=now, ans=i;
	}
	printf("%d\n%lld", ans, now_max);
}
