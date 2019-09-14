#include<stdio.h>

int main(void){
	int T;
	for(scanf("%d", &T); T--;){
		long long price;
		scanf("%d", &price);
		int N;
		for(scanf("%d", &N);N--;){
			long long x, y;
			scanf("%d %d", &x, &y);
			price+=x*y;
		}
		printf("%lld\n",price);
	}
}
