#include<stdio.h>
#include<queue>

struct xy{
	int x, y, cnt;
	xy(){
		scanf("%d %d", &x, &y);
		cnt=0;
	}
	xy(int a, int b, int c){
		x=a, y=b, cnt=c;
	}
};

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		xy start, end;
		int check[301][301] = {0, };
		int ans = -1;
		std::queue<xy> q;
		q.push(start);
		int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
		int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
		while(!q.empty()){
			xy temp = q.front(); q.pop();
			if(temp.x == end.x && temp.y == end.y){
				ans = temp.cnt;
				break;
			}
			check[temp.x][temp.y] = 1;
			for(int i=0; i<8; i++){
				int nowx = temp.x+dx[i];
				int nowy = temp.y+dy[i];
				if(check[nowx][nowy]) continue;
				if(nowx<0 || nowx>=N) continue;
				if(nowy<0 || nowy>=N) continue;
				check[nowx][nowy] = 1;
				int nowcnt = temp.cnt+1;
				xy t(nowx, nowy, nowcnt);
				q.push(t);
			}
		}
		printf("%d\n", ans);
	}
}
