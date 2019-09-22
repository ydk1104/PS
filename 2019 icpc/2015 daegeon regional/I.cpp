#include<stdio.h>
#include<algorithm>


int main(void){
	#define int long long
	int T;
	for(scanf("%d", &T); T--;){
		int a[1000100] = {0, }, max[1000100] = {0,};
		int N;
		scanf("%lld", &N);
		for(int i=0; i<N; i++) scanf("%lld", &a[i]);
		for(int i=N-1; i>=0; i--){
			max[i] = std::max(max[i+1], a[i]);
		}
		int ans=0;
		for(int i=0; i<N; i++){
			if(max[i] - a[i] > 0) ans += max[i] - a[i];
		}
		printf("%lld\n", ans);
	}
}
