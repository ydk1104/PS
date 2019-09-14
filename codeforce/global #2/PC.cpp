#include<stdio.h>

int map[2][501][501];
int stack[501];
int cnt;

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<2; i++){
		for(int j=0; j<N; j++){
			for(int k=0; k<M; k++){
				scanf("%d", &map[i][j][k]);
			}
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(map[0][i][j] != map[1][i][j]) stack[cnt++] = j;
		}
		if(cnt%2 || (cnt&&i==N-1)){
			printf("No");
			return 0;
		}
		while(cnt>0){
			int now = stack[--cnt];
			map[0][i+1][now] = 1-map[0][i+1][now];
		}
	}
	printf("Yes");
}
