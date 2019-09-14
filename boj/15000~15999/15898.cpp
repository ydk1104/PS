#include<stdio.h>

struct M{
	int num[4][4];
	char color[4][4];
	void scan(){
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				scanf("%d", &num[i][j]);
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				scanf(" %c", &color[i][j]);
	}
}m[10];

struct K{
	int num[5][5];
	char color[5][5];
};

K k;
int ans;
int N;

void bomb(K x){
	int temp=0;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(x.color[i][j]=='R') temp+=x.num[i][j]*7;
			if(x.color[i][j]=='B') temp+=x.num[i][j]*5;
			if(x.color[i][j]=='G') temp+=x.num[i][j]*3;
			if(x.color[i][j]=='Y') temp+=x.num[i][j]*2;
		}
	}
	ans=temp>ans?temp:ans;
}

void put(int x, int y, M a){
	for(int i=x; i<x+4; i++){
		for(int j=y; j<y+4; j++){
			map[i][j] = 
		}
	}
}

void BT(int cnt, int now){
	if(cnt==3) return bomb();
	if(now==N) return;
}

int main(void){
	scanf("%d", &N);
	for(int i=0; i<N; i++) m[i].scan();
	BT(0, 0);
	printf("%d", ans);
}
