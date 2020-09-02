#include<stdio.h>

int main(void){
	int T;
	for(scanf("%d", &T); T--;)
	{
		long long N, K;
		scanf("%lld %lld", &N, &K);
		if(N%2 == K%2){
			if(N >= K * K) printf("YES");
			else printf("NO");
		}
		else{
			printf("NO");
		}
		printf("\n");
	}
}
