#include<stdio.h>

int N, cnt;

class node{
	public:
	node* pa;
	node* find(){
		if(this->pa == NULL) return this;
		return this->pa = this->pa->find();
	}
};

int merge(node* x, node* y){
	x = x->find();
	y = y->find();
	if(x==y) return 0;
	y->pa = x;
	return 1;
}

char map[101][101];
node uf[101][101];

void check(){
	int ans = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j] == map[i+1][j]) cnt-=merge(&uf[i][j], &uf[i+1][j]);
			if(map[i][j] == map[i][j+1]) cnt-=merge(&uf[i][j], &uf[i][j+1]);
		}
	}
	printf("%d ", cnt);
}

int main(void){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", &map[i]);
	}
	cnt = N*N;
	check();
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j] == 'G') map[i][j] = 'R';
		}
	}
	check();
}
