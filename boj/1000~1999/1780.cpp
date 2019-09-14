#include<stdio.h>

int map[2222][2222];
int count[3];

int check(int x, int y){
	for(int i=0; i<9; i++){
		if(map[x][y] != map[x+i%3][y+i/3]) return 0;
	}
	return 1;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &map[i][j]);
			count[map[i][j]+1]++;
		}
	}
	int cnt = -2;
	while(N>1){
		for(int i=0; i<N; i+=3){
			for(int j=0; j<N; j+=3){
				if(check(i, j)){
					count[map[i][j]+1] -= 8;
					map[i/3][j/3] = map[i][j];
				}
				else{
					map[i/3][j/3] = --cnt;
				}
			}
		}
		N/=3;
	}
	for(int i=0; i<3; i++) printf("%d\n", count[i]);
}
