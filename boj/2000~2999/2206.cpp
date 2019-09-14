#include<stdio.h>
#include<queue>

using namespace std;

struct xy{
	int x, y, cnt, Break;
	xy(int a, int b, int c, int d){
		x=a, y=b, cnt=c, Break=d;
	}
};

int map[1002][1002];
int check[1002][1002][2];
int N, M, ans;
queue<xy> q;

void push(int x, int y, int cnt, int Break){
	if(x>N || y>M) return;
	if(x==0 || y==0) return;
	if(Break>1) return;
	if(check[x][y][Break]) return;
	check[x][y][Break] = 1;
	q.push(xy(x, y, cnt, Break));
}

void BFS(){
	if(q.empty()) return;
	xy temp = q.front(); q.pop();
	if(temp.x == N && temp.y == M){
		ans = temp.cnt;
		return;
	}
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	for(int i=0; i<4; i++){
		int nowx = temp.x+dx[i];
		int nowy = temp.y+dy[i];
		int nowcnt = temp.cnt + 1;
		int nowBreak = temp.Break + map[nowx][nowy];
		push(nowx, nowy, nowcnt, nowBreak);
	}
	return BFS();
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%1d", &map[i][j]);
		}
	}
	ans = -1;
	xy start = xy(1, 1, 1, 0);
	q.push(start);
	BFS();
	printf("%d", ans);
}
