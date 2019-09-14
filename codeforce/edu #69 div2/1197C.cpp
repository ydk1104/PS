#include<stdio.h>
#include<algorithm>

int a[300001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<N; i++){
		a[i] = a[i+1] - a[i];
	}
	std::sort(a, a+N-1);
	long long ans = 0;
	for(int i=0; i<N-M; i++) ans += a[i];
	printf("%lld", ans);
}
