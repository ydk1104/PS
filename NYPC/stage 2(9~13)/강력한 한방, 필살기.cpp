#include<stdio.h>
#define max(a,b) ((a)>(b) ? (a) : (b))

typedef struct map{
	int atk;
	int hp;
	int team;
}map;

map board[4][3];
int maxatk;
int maxans;

void read(char *read, map *write){
	int temp = 0;
	for(int j=1; read[j]!=0; j++){
		if(read[j]=='/'){
			write->atk = temp;
			temp = 0;
		}
		else{
			temp *= 10;
			temp += read[j]-'0';			
		}
	}
	write->hp = temp;
}

void swap(map *a, map *b){
	map temp = *a;
	*a = *b;
	*b = temp;
}

void score(){
	int score = 0;
	for(int i=0; i<4; i++){
		int check=0, sum=0;
		for(int j=0; j<3; j++){
			check += board[i][j].team;
			sum += board[i][j].atk;
		}
		if(check==3) score+=sum;
		check = 0, sum = 0;
		if(i<2){
			for(int j=0; j<3; j++){
				check += board[i+j][j].team;
				sum += board[i+j][j].atk;
			}
			if(check==3) score+=sum;
		}
		else{
			for(int j=0; j<3; j++){
				check += board[i-j][j].team;
				sum += board[i-j][j].atk;
			}
			if(check==3) score+=sum;
		}
	}
	for(int j=0; j<3; j++){
		for(int k=0; k<=1; k++){
			int check = 0, sum = 0;
			for(int i=0; i<3; i++){
				check += board[k+i][j].team;
				sum += board[k+i][j].atk;	
			}
			if(check==3) score += sum;
		}
	}
	if(score>maxans) maxans = score;
}

int move(int x, int y, int minatk, int minhp){
	int plus[3] = {-1, 0, 1};
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			int nowx = plus[i] + x;
			int nowy = plus[j] + y;
			if(nowx<0 || nowy<0 || nowx>3 || nowy>2) continue;
			if(board[nowx][nowy].atk>minatk && board[nowx][nowy].hp>minhp){
				swap(&board[nowx][nowy], &board[x][y]);
				score();
				swap(&board[nowx][nowy], &board[x][y]);
			}
		}
	}
}

void blank(int x, int y){
	move(x, y, 0, 0);
	board[x][y].team = 1;
	board[x][y].atk = maxatk;
	score();
	board[x][y].team = 0;
	board[x][y].atk = 0;
}

void opposition(int x, int y){
	move(x, y, board[x][y].hp, board[x][y].atk);
}

int main(void){
	char s[10];
	for(int i=0; i<4; i++){
		for(int j=0; j<3; j++){
			scanf("%s", &s);
			if(s[0] != 'X'){
				read(s, &board[i][j]);
				if(s[0] == 'M') board[i][j].team = 1;
				else board[i][j].team = -1;
			}
		}
	}
	int N;
	scanf("%d", &N);
	map spare[11];
	for(int i=1; i<=N; i++){
		scanf("%s", s);
		read(s, spare+i);
		maxatk = max(maxatk, spare[i].atk);
	}
	score();
	for(int i=0; i<4; i++){
		for(int j=0; j<3; j++){
			if(board[i][j].team == 0){
				blank(i, j);
			}
			else if(board[i][j].team == -1){
				opposition(i, j);
			}
		}
	}
	printf("%d", maxans);
}
