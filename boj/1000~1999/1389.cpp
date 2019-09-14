#include<stdio.h>
#define min(a,b) ((a)<(b) ? (a) : (b))

int fr[101][101];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		fr[i][0] = 0;
		for(int j=1; j<=N; j++){
			fr[i][j] = 1000;
		}
		fr[i][i] = 0;
	}
	for(int i=1; i<=M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		fr[a][b] = 1;
		fr[b][a] = 1;
	}
	for(int k=1; k<=N; k++){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				fr[i][j] = min(fr[i][j], fr[i][k] + fr[k][j]);
			}
		}
	}
	int ans = 1;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			fr[i][0] += fr[i][j];
		}
		if(fr[ans][0] > fr[i][0]) ans = i;
	}
	printf("%d", ans);
}
