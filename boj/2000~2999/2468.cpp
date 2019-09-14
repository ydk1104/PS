#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

class spot{
	public:
	int h;
	int check;
	spot* pa;
};

spot map[101][101];

spot* find(spot* x){
	if(x->pa == x) return x;
	return x->pa = find(x->pa);
}

void merge(spot *x, spot *y, int *now){
	if(x->check + y->check != 0) return;
	x = find(x);
	y = find(y);
	if(x==y) return;
	y->pa = x;
	*now = *now-1;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &map[i][j].h);
			map[i][j].check = 0;
			map[i][j].pa = &map[i][j];
		}
	}
	int ans=1;
	for(int h=1; h<=100; h++){
		int now = 0;
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(map[i][j].h<=h) map[i][j].check = 1;
				now += 1-map[i][j].check;
				map[i][j].pa = &map[i][j];
				if(i>1) merge(&map[i][j], &map[i-1][j], &now);
				if(j>1) merge(&map[i][j], &map[i][j-1], &now);
			}
		}
		ans = max(ans, now);
	}
	printf("%d", ans);
}
