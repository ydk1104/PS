#include<stdio.h>
#include<algorithm>

int a[300000];

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++) scanf("%d", a+i);
	std::sort(a, a+N);
	long long ans = 0, cnt = 0;
	for(int i=0; i<N; i++){
		ans += cnt * a[i];
		if(i<K) cnt++;
	}
	printf("%lld",ans);
}
