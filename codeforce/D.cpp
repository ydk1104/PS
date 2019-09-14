#include<stdio.h>

char s[1350][1350];
bool map[5300][5300];

int gcd(int x, int y){
	if(x==y) return x;
	if(y>x){
		int temp = x;
		x = y;
		y = temp;
	}
	if(x%y==0) return y;
	return gcd(y, x%y);
}

void fill(int x, int y, int num){
	for(int i=3; i>=0; i--){
		map[x][y+i] = num%2;
		num/=2;
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N/4; j++){
			int temp;
			scanf("%1x", &temp);
			fill(i, j*4, temp);
		}	
	}
	int g = N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N;){
			int row = 0;
			while(map[i][j] == map[i][j+row] && j+row<N) row++;
			j += row;
			g = gcd(g, row);
		}
		for(int j=0; j<N;){
			int row = 0;
			while(map[j][i] == map[j+row][i] && j+row<N) row++;
			j += row;
			g = gcd(g, row);
		}
	}
	printf("%d", g);
}
