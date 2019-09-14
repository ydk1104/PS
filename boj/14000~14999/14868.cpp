#include<stdio.h>

typedef struct Queue{
	int x;
	int y;
	int cnt;
}Queue;

int world[2001][2001][2];
int cul[101001];
Queue Q[4000001];
int start, end;
int N, K;

void push(int x, int y, int cnt){
	Q[end].x = x;
	Q[end].y = y;
	Q[end].cnt = cnt;
	end++;
	if(end>4000000) end = 0;
}

int find(int x){
	if(cul[x] == -1) return x;
	return cul[x] = find(cul[x]);
}

void merge(int a, int b){
	int ra = find(a);
	int rb = find(b);
	if(ra == rb) return;
	cul[rb] = ra;
	K--;
}

void eat(int x1, int y1, int x2, int y2, int cnt){
	if((x2>N) || (y2>N)) return;
	if((x2 == 0) || (y2 == 0)) return;
	if(world[x2][y2][0] == 0){
		world[x2][y2][0] = world[x1][y1][0];
		world[x2][y2][1] = cnt+1;
		push(x2, y2, cnt+1);
		return;
	}
	if(world[x2][y2][1] > cnt) return;
	if(world[x2][y2][0] < 0){
		merge(world[x1][y1][0], -world[x2][y2][0]);
	}
	else{
		merge(world[x1][y1][0], world[x2][y2][0]);
	}
}

int BFS(){
	Queue temp;
	while(K>1){
		temp = Q[start];
		start++;
		if(start>4000000) start = 0;
		while(world[temp.x][temp.y] < 0 ){
			temp = Q[start];
			start++;
			if(start>4000000) start = 0;
		}
		eat(temp.x, temp.y, temp.x-1, temp.y, temp.cnt);
		eat(temp.x, temp.y, temp.x+1, temp.y, temp.cnt);
		eat(temp.x, temp.y, temp.x, temp.y+1, temp.cnt);
		eat(temp.x, temp.y, temp.x, temp.y-1, temp.cnt);
		world[temp.x][temp.y][0] *= -1;	
	}
	return temp.cnt;
}

int main(void){
	scanf("%d %d", &N, &K);
	for(int i=1; i<=K; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		world[x][y][0] = i;
		world[x][y][1] = 0;
		cul[i] = -1;
		push(x, y, 0);
	}
	printf("%d", BFS());
}
