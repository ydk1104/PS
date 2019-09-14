#include<stdio.h>
#include<algorithm>

int a[1001];

int main(void){
	int T;
	for(scanf("%d", &T); T--;){
		int N;
		scanf("%d", &N);
		for(int i=0; i<N; i++) scanf("%d", &a[i]);
		int now=0, ans=-1000;
		for(int i=0; i<N; i++){
			now += a[i];
			ans = std::max(ans, now);
			if(now<0) now=0;
		}
		printf("%d\n",ans);
	}
}
