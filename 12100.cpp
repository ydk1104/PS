#include<stdio.h>
#define max(a,b) (a>b) ? a : b

int N;

int move(int map[25][], int cnt, int max){
	if(cnt==5) return max;
	int temp[25][25][4];
	for(int i=0; i<=3; i++){
		for(int j=1; j<=N; j++){
			for(int k=1; k<=N; k++){
				temp[i][j][k] = map[j][k];
			}
		}
		move(temp[25][], cnt+1, max);
	}
	
}

int main(void){
	int map[25][25];
	scanf("%d", &N);
	int max = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &map[i][j]);
			max = max(max, map[i][j]);
		}
	}
	int ans = move(map[], 0, max);
	printf("%d", ans);
}
