#include<stdio.h>

typedef struct xy{
	int x;
	int y;
}xy;

int block[1001][1001];
int countblank[1001][1001];
xy stack[1001001];
int top;
int N;

void push(int x, int y){
	stack[top].x = x;
	stack[top++].y = y;
}

xy pop(){
	xy temp = stack[--top];
	return temp;
}

void count(int x, int y){
	int cnt = 0;
	if(block[x][y] == -1) countblank[x][y]++;
	if(block[x+1][y] == -1) countblank[x][y]++;
	if(block[x+1][y+1] == -1) countblank[x][y]++;
	if(countblank[x][y] == 1) push(x, y);
}

void minusblank(int x, int y){
	if(x>N || y>N || x<y) return;
	countblank[x][y]--;
	if(countblank[x][y] == 1) push(x,y);
//	printf("%d %d %d\n", x, y, countblank[x][y]);
}

void fill(int x, int y){
	if(block[x][y] == -1){
		block[x][y] = (block[x+1][y] + block[x+1][y+1])%100;	
		minusblank(x-1, y);
		minusblank(x-1, y-1);
		}
	else if(block[x+1][y] == -1){
		block[x+1][y] = (100+block[x][y] - block[x+1][y+1])%100;
		minusblank(x+1, y);
		minusblank(x, y-1);
		}
	else if(block[x+1][y+1] == -1){
		block[x+1][y+1] = (100+block[x][y] - block[x+1][y])%100;	
		minusblank(x+1, y+1);
		minusblank(x, y+1);
	}
}

int main(void){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=i; j++){
			scanf("%d", &block[i][j]);
		}
	}
	for(int j=1; j<=N-1; j++){
		for(int k=1; k<=j; k++){
			count(j, k);
		}
	}
	while(top){
		xy temp = pop();
		fill(temp.x, temp.y);
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=i; j++){
			printf("%d ", block[i][j]);
		}
		printf("\n");
	}
}
