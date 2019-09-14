#include<stdio.h>
#include<algorithm>

int map[101][101];
const int MAX = 1<<29;

int main(void){
	int N, s, e, M, temp;
	scanf("%d %d %d %d", &N, &s, &e, &M);
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) map[i][j] = MAX;
	for(int i=0; i<M; i++){
		int x, y, cost;
		scanf("%d %d %d", &x, &y, &cost);
		map[x][y] = cost;
	}
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		for(int j=0; j<N; j++) if(map[i][j]!=MAX) map[i][j] -= x;
		if(i==s) temp=x;
	}
	for(int k=0; k<N; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				map[i][j] = std::min(map[i][j], map[i][k]+map[k][j]);
				printf("%d\n", map[i][j]);
			}
		}
	}
	if(map[s][e] == MAX) printf("gg");
	printf("%d", temp-map[s][e]);
}
