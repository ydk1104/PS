#include<stdio.h>

int main(void){
	int T;
	for(scanf("%d", &T); T--;){
		int N,M;
		scanf("%d %d", &N, &M);
		if(N<12 || M<4) printf("-1\n");
		else printf("%d\n", 11*M+4);
	}
}
