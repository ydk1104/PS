#include<stdio.h>

int map[5][5];
int check[1000000];
int ans;

void DFS(int x, int y, int cnt, int num){
	if(x<0 || y<0) return;
	if(x>4 || y>4) return;
	cnt++;
	num *= 10;
	num += map[x][y];
	if(cnt == 6){
		if(!check[num]){
			check[num] = 1;
			ans++;
		}
		return;
	}
	DFS(x+1, y, cnt, num);
	DFS(x-1, y, cnt, num);
	DFS(x, y+1, cnt, num);
	DFS(x, y-1, cnt, num);
}

int main(void){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			scanf("%d", &map[i][j]);
		}
	}
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			DFS(i, j, 0, 0);
		}
	}
	printf("%d", ans);
}
