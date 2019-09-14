#include<stdio.h>

typedef struct xy{
	int x;
	int y;
	int cnt;
}xy;

int map[127][127];
int dp[127][127];
xy PQ[1000];
int num = 1;
int N;

void swap(xy *a, xy *b){
	xy temp = *a;
	*a = *b;
	*b = temp;
}

void put(int x, int y, int cnt){
	PQ[num].x = x;
	PQ[num].y = y;
	PQ[num].cnt = cnt;
	int i = num;
	num++;
	while((PQ[i].cnt < PQ[i/2].cnt) && (i!=1)){
		swap(&PQ[i], &PQ[i/2]);
		i = i/2;
	}
}

xy pop(void){
	if(num == 1){
		return PQ[0];
	}
	xy temp = PQ[1];
	num--;
	PQ[1] = PQ[num];
	PQ[num] = PQ[0];
	int i = 1;
	while((i*2<=num-1) && ((PQ[i].cnt > PQ[i*2].cnt) || ((PQ[i].cnt > PQ[i*2+1].cnt) && (PQ[i*2+1].cnt!=-1)))){
		if((PQ[i*2].cnt<PQ[i*2+1].cnt) || (PQ[i*2+1].cnt == -1)){
			swap(&PQ[i], &PQ[i*2]);
			i = i*2;
		}
		else{
			swap(&PQ[i], &PQ[i*2+1]);
			i = i * 2 + 1;
		}
	}
	if(dp[temp.x][temp.y] == -2){
		return pop();
	}
	return temp;
}

void check(int x, int y, int cnt){
	if(x<1 || x>N || y<1 || y>N){
		return;
	}
	if(dp[x][y] == -2){
		return;
	}
	if(dp[x][y] != -1 && dp[x][y] <= cnt){
		return;
	}
	dp[x][y] = cnt;
	put(x, y, cnt);
}

int find(){
	xy a = pop();
	int x = a.x;
	int y = a.y;
	int cnt = a.cnt;
	if(x==N && y==N) return cnt;
	dp[x][y] = -2;
	check(x+1, y, cnt+map[x+1][y]);
	check(x-1, y, cnt+map[x-1][y]);
	check(x, y+1, cnt+map[x][y+1]);
	check(x, y-1, cnt+map[x][y-1]);
	return find();
}

int main(void){
	scanf("%d", &N);
	int cnt = 1;
	while(N!=0){
		for(int i=0; i<1000; i++){
			PQ[i].cnt = -1;
		}
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				scanf("%d", &map[i][j]);
				dp[i][j] = -1;
			}
		}
		put(1, 1, map[1][1]);
		dp[1][1] = map[1][1];
		printf("Problem %d: %d\n", cnt, find());
		cnt++;
		while(num>1){
			pop();
		}
		scanf("%d", &N);
	}
}
