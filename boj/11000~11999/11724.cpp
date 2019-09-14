#include<stdio.h>

int N, M, uf[1001], x, y;

int find(int x){
	if(!uf[x]) return x;
	return uf[x] = find(uf[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if(x==y) return;
	N--;
	uf[y] = x;
}

int main(void){
	scanf("%d %d", &N, &M);
	for(; M>0; M--){
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	printf("%d", N);
}
