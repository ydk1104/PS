#include<stdio.h>
#define Qmax 1000000

typedef struct to{
	int h;
	int y;
	int x;
	int cnt;	
}to;

to Queue[Qmax+1];
int start = 0;
int end = 0;
int M, N, H;
int map[102][102][102];
int ans;

void put(int h, int y, int x, int cnt){
	if(h==0 || h>H || y==0 || y>N || x==0 || x>M){
		return;
	}
	if(map[h][y][x] != 0){
		return;
	}
	Queue[end].x = x;
	Queue[end].y = y;
	Queue[end].h = h;
	Queue[end].cnt = cnt;
	end++;
	if(end>Qmax){
		end = 0;
	}
}

to pop(){
	to temp = Queue[start];
	start++;
	if(start>Qmax){
		start = 0;
	}
	return temp;
}

int find(){
	to mato = pop();
	int x = mato.x;
	int y = mato.y;
	int h = mato.h;
	int cnt = mato.cnt;
	if(map[h][y][x] == 0){
		map[h][y][x] = 1;
		put(h+1, y, x, cnt+1);
		put(h-1, y, x, cnt+1);
		put(h, y+1, x, cnt+1);
		put(h, y-1, x, cnt+1);
		put(h, y, x+1, cnt+1);
		put(h, y, x-1, cnt+1);
		return cnt;
	}
	return ans;
}

int main(void){
	scanf("%d %d %d", &M, &N, &H);
	for(int i=1; i<=H; i++){
		for(int j=1; j<=N; j++){
			for(int k=1; k<=M; k++){
				scanf("%d", &map[i][j][k]);
				if(map[i][j][k] == 1){
					map[i][j][k] = 0;
					put(i, j, k, 0);
				}
			}
		}
	}
	while(start != end){
		ans = find();
	}
	for(int i=1; i<=H; i++){
		for(int j=1; j<=N; j++){
			for(int k=1; k<=M; k++){
					if(map[i][j][k] == 0){
						printf("-1\n");
						return 0;
					}
				}
			}
		}
	printf("%d\n", ans);
	return 0;
}
