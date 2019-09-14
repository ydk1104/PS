#include<stdio.h>

int main(void){
	int N, M;
	char art[] = {'#', 'o', '+', '-', '.', '.'};
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int i=1; i<=M; i++){
			int r, g, b;
			scanf("%d %d %d", &r, &g, &b);
			int now = r*2126+g*7152+b*722;
			printf("%c", art[now/510000]);
		}
		if(i!=N) printf("\n");
	}
	
}
