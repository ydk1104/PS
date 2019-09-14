#include<stdio.h>

typedef struct po{
	int x;
	int y;
	int cnt;
}po;

char map[101][101];
int d[101][101];
po queue[1000001];
int start;
int end;
int N, M;

void put(int x, int y, int cnt){
	if(x>=0 && x<=N-1 && y>=0 && y<=M-1){
		if(d[x][y] <= cnt && d[x][y] >= 0){
			return;
		}
		if(map[x][y] == '0'){
			d[x][y] = 0;
			return;
		}
		d[x][y] = cnt;
		queue[end].x = x;
		queue[end].y = y;
		queue[end].cnt = cnt;
		end++;
	}
	if(end>1000000){
		end = 0;
	}
}

int BFS(void){
	int x = queue[start].x;
	int y = queue[start].y;
	int cnt = queue[start].cnt;
	start++;
	if(start>1000000){
		start = 0;
	}
	if(x==N-1 && y==M-1){
		return cnt;
	}
	put(x-1, y, cnt+1);
	put(x+1, y, cnt+1);
	put(x, y-1, cnt+1);
	put(x, y+1, cnt+1);
	return BFS();
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%s", &map[i]);
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			d[i][j] = -1;
		}
	}
	put(0, 0, 1);
	int ans = BFS();
	printf("%d", ans);
}
