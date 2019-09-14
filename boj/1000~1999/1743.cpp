#include<stdio.h>
#define max(a,b) (a>b) ? (a) : (b)

typedef struct xy{
	int x;
	int y;
};

int N, M, K;
int map[101][101];
xy uf[101][101];

xy find(xy X){
	if(uf[X.x][X.y].x < 0) return X;
	return X = find(uf[X.x][X.y]);
}
int merge(xy X, xy Y){
	xy a = find(X);
	xy b = find(Y);
	if(a.x==b.x && a.y == b.y) return -1;
	uf[a.x][a.y].x += uf[b.x][b.y].x;
	uf[b.x][b.y] = a;
	return 0-uf[a.x][a.y].x;
}

int main(void){
	scanf("%d %d %d", &N, &M, &K);
	for(int i=1; i<=K; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}
	int ans = 1;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			uf[i][j].x = -1;
			if(map[i][j] == 1){
				if(map[i-1][j] == 1){
					xy a;
					a.x = i;
					a.y = j;
					xy b;
					b.x = i-1;
					b.y = j;
					int temp = merge(a, b);
					ans = max(ans, temp);
				}
				if(map[i][j-1] == 1){
					xy a;
					a.x = i;
					a.y = j;
					xy b;
					b.x = i;
					b.y = j-1;
					int temp = merge(a, b);
					ans = max(ans, temp);
				}
			}
		}
	}
	printf("%d", ans);
}
