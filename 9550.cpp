#include<stdio.h>

int main(void){
	int T;
	for(scanf("%d", &T); T--;){
		int N, K;
		scanf("%d %d", &N, &K);
		int ans=0;
		for(int i=0; i<N; i++){
			int x;
			scanf("%d", &x);
			ans += x/K;
		}
		printf("%d\n",ans);
	}
}
