#include<stdio.h>
#define min(a,b) ((a)>(b) ? (b) : (a))
#define Qmax 100000

typedef struct point{
	int x;
	int y;
	int time;
	int row;
}point;

char map[501][51];
int dp[501][501][51];
int ans;
int N, M, K;
point Queue[Qmax+1];
/*
void push(int x, int y, int time){
	Queue[end].x = x;
	Queue[end].y = y;
	Queue[end++].time = time;
	if(end>Qmax) end=0;
}

point pop(){
	point temp = Queue[start++];
	if(start>Qmax) start=0;
	return temp;
}
*/
int DFS(int x, int y, int plus, int row);

int check(int x, int y, int kick, int row){
	if(map[x][y] == '#') return N+1;
	if(map[x-1][y] == '#'){
		if(row-K+1==x) return N+1;
		kick++;
		map[x-1][y]--;
	}
	int plus = DFS(x-1, y, kick, row-1);
	if(kick) map[x-1][y] = '#';
	return plus;
}

int DFS(int x, int y, int plus, int row){
	if(dp[x][row][y] != -1) return dp[x][row][y];
	int minx = row-K+1;
	int maxx = row;
	if(minx <= 1) return plus;
	int nowplus = check(x, y, 0, row);
	if(x<maxx) nowplus = min(nowplus, check(x+1, y, 0, row));
	if(x>minx) nowplus = min(nowplus, check(x-1, y, 0, row));
	if(y>0) nowplus = min(nowplus, check(x, y-1, 0, row));
	if(y<M) nowplus = min(nowplus, check(x, y+1, 0, row));
	return dp[x][row][y] = plus + nowplus;
}

int main(void){
	scanf("%d %d %d", &N, &M, &K);
	for(int i=1; i<=N; i++){
		scanf("%s", &map[i]);
		for(int j=1; j<=N; j++){
			for(int k=0; k<M; k++) dp[i][j][k] = -1;
		}
	}
//	push(1, 1, 0, 1);
	DFS(N, 0, 0, N);
	if(M==1){
		int cnt = 0;
		for(int i=1; i<=N; i++){
			if(map[i][0] == '#') cnt++;
		}
		printf("%d", cnt);
	}
	else printf("%d", dp[N][N][0]);
}
