#include<stdio.h>

class pair{
	public:
		int x;
		int y;
};

class queue{
	public:
		pair q[1001];
		int start;
		int end;
		void push(int x, int y){
			q[end].x = x;
			q[end].y = y;
			end++;
		}
		pair pop(){
			return q[start++];
		}
		void clear(){
			start = 0;
			end = 0;
		}
		int empty(){
			if(start == end) return 1;
			return 0;
		}
};

int N, M;
int map[8][8];
pair blank[64];
int cnt;
queue Q;

int check(int x, int y){
	if(x<0 || y<0) return 0;
	if(x>=N || y>=M) return 0;
	return 1;
}

int find(int x, int y, int z){
	int temp[8][8];
	Q.clear();
	int now = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			temp[i][j] = map[i][j];
			if(temp[i][j] == 2) Q.push(i, j);
			if(temp[i][j] == 0) now++;
		}
	}
	now -= 3;
	temp[blank[x].x][blank[x].y] = 1;
	temp[blank[y].x][blank[y].y] = 1;
	temp[blank[z].x][blank[z].y] = 1;
	while(!Q.empty()){
		pair t = Q.pop();
		if(check(t.x-1, t.y) && temp[t.x-1][t.y] == 0) now--, temp[t.x-1][t.y]=2, Q.push(t.x-1, t.y);
		if(check(t.x+1, t.y) && temp[t.x+1][t.y] == 0) now--, temp[t.x+1][t.y]=2, Q.push(t.x+1, t.y);
		if(check(t.x, t.y-1) && temp[t.x][t.y-1] == 0) now--, temp[t.x][t.y-1]=2, Q.push(t.x, t.y-1);
		if(check(t.x, t.y+1) && temp[t.x][t.y+1] == 0) now--, temp[t.x][t.y+1]=2, Q.push(t.x, t.y+1);
	}
	return now;
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &map[i][j]);
			if(!map[i][j]){
				blank[cnt].x = i;
				blank[cnt++].y = j;
			}
		}
	}
	int ans=0;
	for(int i=0; i<cnt-2; i++){
		for(int j=i+1; j<cnt-1; j++){
			for(int k=j+1; k<cnt; k++){
				int now = find(i, j, k);
				if(now>ans) ans=now;
			}
		}
	}
	printf("%d", ans);
}
