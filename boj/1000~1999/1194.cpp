#include<stdio.h>
#include<queue>
#include<tuple>

struct xy{
	int x;
	int y;
	int check;
	int ans;
	xy(){}
	xy(int a, int b, int c, int d):x(a),y(b),check(c),ans(d){}
};

std::queue<xy> q;

char s[52][52];
bool visited[52][52][64];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%s",s[i]+1);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(s[i][j] == '0') q.push(xy(i,j,0,0)), visited[i][j][0]++;
			if(s[i][j] == '#') s[i][j]=0;
		}
	}
	v:;
	int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
	while(!q.empty()){
		xy now = q.front(); q.pop();
//		printf("%d %d %d %d %c\n", now.x, now.y, now.check, now.ans, s[now.x][now.y]);
		for(int i=0; i<4; i++){
			int nx=now.x+dx[i], ny=now.y+dy[i], nc=now.check, na=now.ans;
			if(!s[nx][ny] || visited[nx][ny][nc]) continue;
			if(s[nx][ny]=='1'){
				printf("%d",na+1);
				return 0;
			}
			if(s[nx][ny]>='a') nc |= 1<<s[nx][ny]-'a';
			else if(s[nx][ny]>='A' && !(nc & 1<<s[nx][ny]-'A')) continue;
			q.push(xy(nx,ny,nc,na+1));
			visited[nx][ny][nc]++;
		}
	}
	printf("-1");
}
