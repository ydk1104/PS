#include<stdio.h>
#include<algorithm>

int a[10001];

int main(void){
	int T;
	for(scanf("%d", &T); T--;){
		int N;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%d", &a[i]);
		}
		std::sort(a, a+N);
		int ans=0;
		for(int i=2; i<N; i++){
			ans = std::max(ans, a[i]-a[i-2]);
		}
		printf("%d\n", ans);
	}
}
