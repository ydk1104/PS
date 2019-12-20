#include<stdio.h>

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int coin[2][10001] = {0,};
	coin[0][0] = coin[1][0] = 1;
	while(M--){
		for(int i=0; i<=N; i++) coin[M&1][i] = 0;
		int x,y;
		scanf("%d %d", &x, &y);
		for(int i=0; i<=y; i++){
			for(int j=x*i; j<=N; j++){
				coin[M&1][j] += coin[(M&1)^1][j-x*i];
			}
		}
	}
	printf("%d", coin[0][N]);
}
