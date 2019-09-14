#include<stdio.h>

typedef struct xy{
	int x;
	int y;
	int move;
}xy;

int check(xy a, xy b){
	xy c = robot[1][a.move];
	xy d = robot[1][b.move];
	
}

int N;
xy robot[2][11];

int BT(int now, int check[]){
	if(now>N){
		for(int i=0; i<N; i++){
			printf("%d\n", robot[0][i].move);
		}
		return 0;
	}
	for(int i=0; i<N; i++){
		if(!check[i]){
			check[i] = 1;
			robot[0][now].move = i;
			int flag = 0;
			for(int j=0; j<now; j++){
				flag += check(robot[0][now], robot[0][j]);
			}
			if(!flag) flag = BT(now+1, check);
			if(!flag) return 0;
			check[i] = 0;
			robot[0][now].move = 0;
		}
	}
	return 1;
}

int main(void){
	scanf("%d", &N);
	for(int i=0; i<=1; i++){
		for(int j=0; j<N; j++){
			scanf("%d %d", robot[i][j].x, robot[i][j].y);
		}
	}
	int check[11] = {0,};
	BT(0, check);
}
