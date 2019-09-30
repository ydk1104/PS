#include<stdio.h>

int N;
char s[5][5];
char block[2][5][5];
int check, animal;

int dfs(int x, int y, int visited[4][4]){
	if(x<0 || y<0 || x>=N || y>=N) return 0;
	if(animal && s[x][y]!='.' && animal != s[x][y]) return -1;
	if(visited[x][y]) return 0;
	visited[x][y] = 1;
	if(s[x][y]!='.')animal |= s[x][y];
	int check = 0;
	if(!block[0][x+1][y]) check |= dfs(x+1, y, visited);
	if(!block[0][x][y]) check |= dfs(x-1, y, visited);
	if(!block[1][x+1][y+1]) check |= dfs(x, y+1, visited);
	if(!block[1][x+1][y]) check |= dfs(x, y-1, visited);
	return check;
}

int f(){
	int visited[4][4] = {0,};
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visited[i][j]) continue;
			animal = 0;
			int result = dfs(i, j, visited);
			if(result == -1) return 0;
		}
	}
	return check=1;
}

void BT(int now, int x, int y, int visited[5][5]){
	if(check) return;
	if(x>N || y>N || x<0 || y<0) return;
	if(visited[x][y]) return;
	if(x==N && y==N){
		if(!(check = f())) return;
		printf("yes\n");
		for(int i=0; i<2*N+3; i++){
			for(int j=0; j<4*N+3; j++){
				if(i==0 || i==2*N+2 || j==0 || j==4*N+2) printf("#");
				else if(i%2==1 && j%4==1) printf("+");
				else if(i%2==1){
					if(block[0][i/2][(j-1)/4]) printf("-");
					else printf(" ");
				}
				else if(j%4==1){
					if(block[1][i/2][(j-1)/4]) printf("|");
					else printf(" ");
				}
				else if(i%2==0 && j%4==3) printf("%c",s[i/2-1][j/4]);
				else printf(" ");
			}
			printf("\n");
		}
		return;
	}
	visited[x][y] = 1;
	if(y<=N ){block[0][x][y]++; BT(now, x, y+1, visited); block[0][x][y]--;}
	if(x) {block[0][x][y-1]++; BT(now, x, y-1, visited); block[0][x][y-1]--;}
	if(x<=N){block[1][x+1][y]++; BT(now, x+1, y, visited); block[1][x+1][y]--;}
	if(y) {block[1][x][y]++; BT(now, x-1, y, visited); block[1][x][y]--;}
	visited[x][y] = 0;
}

int main(void){
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%s", &s[i]);
	int visited[5][5] = {0, };
	BT(0, 0, 0, visited);
	if(!check) printf("no");
}
