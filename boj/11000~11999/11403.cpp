#include<stdio.h>

int map[101][101];
int ans[101][101];
int N;

void DFS(int start, int now){
	if(ans[start][now]>0) return;
	ans[start][now]++;
	for(int i=0; i<N; i++){
		if(map[now][i] && ans[start][i]<1) DFS(start, i);
	}
}

int main(void){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &map[i][j]);
		}
		ans[i][i]--;
	}
	for(int i=0; i<N; i++) DFS(i, i);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}
