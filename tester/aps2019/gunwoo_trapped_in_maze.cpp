#include<stdio.h>
#include<queue>

int N, M;
int map[502][502];
int sum[502][502][4];
bool visited[502][502][2][10];
int dx[4] = {0,0,-1,1,}, dy[4] = {-1,1,0,0};

void BFS(){
	struct xy{
		int x, y, day, sun, move;
		void print(){printf("%d %d %d %d %d\n", x, y, day, sun, move);}
	};
	std::queue<xy> q;
	q.push({1,1,1,1,0});
	while(q.size()){
		xy now = q.front(); q.pop();
//		now.print();
		if(now.x == N && now.y == N){
			printf("%d %s", now.day, now.sun ? "sun" : "moon");
			return;
		}

		if(now.sun){
			for(int i=0; i<4; i++){
				xy temp = {now.x+dx[i], now.y+dy[i], now.day, now.sun, now.move+1};
				if(map[temp.x][temp.y]) continue;
				if(temp.move == M) temp.move = 0, temp.sun--;
				if(temp.sun == -1) temp.sun = 1, temp.day++;
				if(!visited[temp.x][temp.y][temp.sun][temp.move]){
					visited[temp.x][temp.y][temp.sun][temp.move] = true;
					q.push(temp);
				}
			}			
		}
		else{
			for(int i=0; i<4; i++){
				xy temp = now;
				temp.move++;
//				if(!sum[temp.x][temp.y][i]) sum[temp.x][temp.y][i] = 1;
//				if(i<2) temp.x += sum[temp.x][temp.y][i]+1;
//				else temp.y += sum[temp.x][temp.y][i]+1;
				temp.x += dx[i]; temp.y += dy[i];
				temp.x += (sum[temp.x][temp.y][i]) * dx[i];
				temp.y += (sum[temp.x][temp.y][i]) * dy[i];
				if(temp.move == M) temp.move = 0, temp.sun--;
				if(temp.sun == -1) temp.sun = 1, temp.day++;
				if(!visited[temp.x][temp.y][temp.sun][temp.move]){
					visited[temp.x][temp.y][temp.sun][temp.move] = true;
					q.push(temp);
				}
			}
		}
	}
	printf("-1");
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=0; i<=N+1; i++) for(int j=0; j<2; j++) for(int k=0; k<M; k++)
		visited[i][0][j][k] = visited[0][i][j][k] = visited[i][N+1][j][k] = visited[N+1][i][j][k] = true;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &map[i][j]);
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(map[i][j]) sum[i][j][0] = sum[i][j-1][0] + map[i][j];
			if(map[j][i]) sum[j][i][2] = sum[j-1][i][2] + map[j][i];
		}
		for(int j=N; j; j--){
			if(map[i][j]) sum[i][j][1] = sum[i][j+1][1] + map[i][j];
			if(map[j][i]) sum[j][i][3] = sum[j+1][i][3] + map[j][i];
		}
	}
	BFS();
}
