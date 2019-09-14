#include<stdio.h>
#define MAX 1000

typedef struct Queue{
	int x[100000];
	int y[100000];
	int cnt[100000];
	int top = 100;
	int bot = 100;
}Queue;

int map[102][102];
int ans[102][102];
int N, M;
Queue Q;

void pushtop(int x, int y, int cnt){
	Q.x[Q.top] = x;
	Q.y[Q.top] = y;
	Q.cnt[Q.top] = cnt;
	Q.top++;
}

void pushbot(int x, int y, int cnt){
	if(Q.bot==0 || Q.cnt[Q.top-1] == cnt) return pushtop(x, y, cnt);
	Q.bot--;
	Q.x[Q.bot] = x;
	Q.y[Q.bot] = y;
	Q.cnt[Q.bot] = cnt;
}

void check(int x, int y, int cnt){
	if(x==0 || y==0) return;
	if(x>M || y>N) return;
	if(ans[x][y] != -1) return;
	if(map[x][y] == 1){
		pushtop(x, y, cnt+1);
	}
	else{
		pushbot(x, y, cnt);
	}
}

void BFS(){
	int x = Q.x[Q.bot];
	int y = Q.y[Q.bot];
	int cnt = Q.cnt[Q.bot];
	Q.bot++;
	if(x==0 || y==0) return BFS();
	if(x>M || y>N) return BFS();
	if(x==M && y==N){
		ans[x][y] = cnt;
		return;
	}
	if(ans[x][y] != -1) return BFS();
	ans[x][y] = cnt;
	check(x+1, y, cnt);
	check(x-1, y, cnt);
	check(x, y+1, cnt);
	check(x, y-1, cnt);
	return BFS();
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=1; i<=M; i++){
		for(int j=1; j<=N; j++){
			scanf("%1d", &map[i][j]);
			ans[i][j] = -1;
		}
	}
	pushtop(1, 1, 0);
	BFS();
	printf("%d", ans[M][N]);
}
