#include<stdio.h>
#define min(a,b) ((a)>(b)?(b):(a))

int a[200001];
long long ans, prev=2000000000;

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	for(int i=N-1; i>=0; i--){
		prev = min(prev-1, a[i]);
		if(prev<0) break;
		ans += prev;
	}
	printf("%lld\n", ans);
}
