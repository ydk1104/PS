#include<stdio.h>

int map[1001][1001][2];

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			scanf("%d", &map[i][j][0]);
			map[i][j][1] = max(map[i-1][j][1], map[i][j-1][1]) + map[i][j][0];
		}
	}
	printf("%d", map[N][M][1]);
}
