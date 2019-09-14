#include<stdio.h>

class set{
	public:
	int check;
	set* pa;
};

set map[52][52];

set* find(set* x){
	if(x->pa == x) return x;
	return x->pa = find(x->pa);
}

void merge(set* x, set* y, int* ans){
	if(x->check == 0 || y->check == 0) return;
	x = find(x);
	y = find(y);
	if(x==y) return;
	*ans = *ans - 1;
	y->pa = x;
}

int main(void){
	int W, H;
	scanf("%d %d", &W, &H);
	while(W != 0 && H != 0){
		int ans = 0;
		for(int i=1; i<=H; i++){
			for(int j=1; j<=W; j++){
				scanf("%d", &map[i][j].check);
				map[i][j].pa = &map[i][j];
				if(map[i][j].check) ans++;
			}
		}
		for(int i=1; i<=H; i++){
			for(int j=1; j<=W; j++){
				if(i!=H) merge(&map[i][j], &map[i+1][j], &ans);
				if(j!=W) merge(&map[i][j], &map[i][j+1], &ans);
				if(i!=H && j!=W) merge(&map[i][j], &map[i+1][j+1], &ans);
				if(i!=H && j!=1) merge(&map[i][j], &map[i+1][j-1], &ans);
			}
		}
		printf("%d\n", ans);
		scanf("%d %d", &W, &H);
	}
}
