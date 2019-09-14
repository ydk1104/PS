#include<stdio.h>

int map[101][101];

int main(void){
	int N, M;
	scanf("%d\n%d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(i!=j) map[i][j] = 100000000;
		}
	}
	for(;M--;){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		map[x][y] = map[x][y]>z ? z : map[x][y];
	}
	for(int k=1; k<=N; k++){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				int temp = map[i][k]+map[k][j];
				map[i][j] = map[i][j]>temp ? temp : map[i][j];
			}
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(map[i][j] >= 100000000) map[i][j]=0;
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}
