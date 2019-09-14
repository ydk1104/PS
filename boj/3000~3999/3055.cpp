#include<stdio.h>

typedef struct Queue{
	int x;
	int y;
}Q;

char map[51][51];
Q q[10001][2]; // 0 °í½¿µµÄ¡ 1 ¹° 
int cnt[2];
int start[2];
int flag;

void push(int num, int x, int y){
	q[cnt[num]][num].x = x;
	q[cnt[num]][num].y = y;
	cnt[num]++;
	cnt[num] %= 10000;
}

Q pop(int num){
	Q temp = q[start[num]++][num];
	start[num] %= 10000;
	return temp;
}

void fill(int x, int y){
	if(map[x][y] == '.'){
		map[x][y] = '*';
		push(1, x, y);
	}
}

void move(int x, int y){
	if(map[x][y] == 0) return;
	if(map[x][y] == 'D') flag=1;
	else if(map[x][y] == '.'){
		map[x][y] = 'S';	
		push(0, x, y);
	}
}

int BFS(int count){
	int temp = cnt[1]-start[1];
	int a = temp;
	if(temp<0) temp+=10000;
	while(temp>0){
		Q now = pop(1);
		fill(now.x+1, now.y);
		fill(now.x-1, now.y);
		fill(now.x, now.y+1);
		fill(now.x, now.y-1);
		temp--;
	}
	temp = cnt[0]-start[0];
	if(a==0 && temp==0) return -1;
	if(temp<0) temp+=10000;
	while(temp>0){
		Q now = pop(0);
		move(now.x+1, now.y);
		move(now.x-1, now.y);
		move(now.x, now.y+1);
		move(now.x, now.y-1);
		temp--;
	}
	if(flag) return count+1;
	return BFS(count+1);
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		getchar();
		for(int j=1; j<=M; j++){
			scanf("%c", &map[i][j]);
			if(map[i][j] == 'S') push(0, i, j);
			if(map[i][j] == '*') push(1, i, j);
		}
	}
	int ans = BFS(0);
	if(flag) printf("%d", ans);
	else printf("KAKTUS");
}
