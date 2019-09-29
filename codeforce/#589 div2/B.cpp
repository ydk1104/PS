#include<stdio.h>

int map[1001][1001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int x;
	for(int i=0; i<N; i++){
		scanf("%d", &x);
		for(int j=0; j<x; j++) map[i][j] = 2;
		map[i][x] = 1;
	}
	for(int i=0; i<M; i++){
		scanf("%d", &x);
		for(int j=0; j<x; j++) map[j][i] = map[j][i]==1 ? -1 : 2;
		map[x][i] = map[x][i]==2 ? -1 : 1;
	}
	int ans = 1;
	int mod = 1e9+7;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
//			printf("%d ", map[i][j]);
			if(!~map[i][j]) ans=0;
			if(!map[i][j]) ans*=2;
			if(ans > mod) ans -= mod;
		}
//		printf("\n");
	}
	printf("%d", ans);
}
