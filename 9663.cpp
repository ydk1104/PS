#include<stdio.h>

int map[31][31], N, ans;

int check_x[20], check_y[20], check_xy[40], check_yx[40];

void setQueen(int x, int y, int set){
	check_y[y]+=set;
	check_xy[y-x+N]+=set;
	check_yx[x+y]+=set;
}

int check(int x, int y){
	if(check_y[y]) return 1;
	if(check_xy[y-x+N]) return 1;
	if(check_yx[x+y]) return 1;
	return 0;
}

void BT(int map[31][31], int num, int x, int y){
	if(num == N){
		ans++;
		return;
	}
	if(y>=N) return;
	if(check(x, y)) return BT(map, num, x, y+1);
	setQueen(x, y, 1);
	BT(map, num+1, x+1, 0);
	setQueen(x, y, -1);
	BT(map, num, x, y+1);
}

int main(void){
	scanf("%d", &N);
	BT(map, 0, 0, 0);
	printf("%d", ans);
}
