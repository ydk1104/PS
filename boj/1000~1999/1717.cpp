#include<stdio.h>

int uf[1000001];

int find(int x){
	if(uf[x] < 0) return x;
	return uf[x] = find(uf[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if(x==y) return;
	uf[y] = x;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<=N; i++){
		uf[i] = -1;
	}
	for(int i=1; i<=M; i++){
		int check, x, y;
		scanf("%d %d %d", &check, &x, &y);
		if(!check){
			merge(x, y);
		}
		else{
			if(find(x) == find(y)) printf("YES\n");
			else printf("NO\n");
		}
	}
}
