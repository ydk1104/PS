#include<stdio.h>

int map[9][9];
int ans = 81;

int check(int x, int y, int num){
	for(int i=0; i<9; i++){
		if(map[x][i] == num) return 0;
		if(map[i][y] == num) return 0;
	}
	for(int i = x/3*3; i<x/3*3+3; i++){
		for(int j=y/3*3; j<y/3*3+3; j++){
			if(map[i][j] == num) return 0;
		}
	}
	return 1;
}

void back(int x, int y){
	if(ans==0) return;
	if(y==9){
		x++;
		y=0;
	}
	if(map[x][y]) return back(x, y+1);
	for(int i=1; i<=9; i++){
		if(check(x, y, i)){
			map[x][y] = i;
			ans--;
			back(x, y+1);
			if(ans==0) return;
			map[x][y] = 0;
			ans++;
		}
	}
}

int main(void){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] != 0) ans--;
		}
	}
	back(0, 0);
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}
