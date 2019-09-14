#include<stdio.h>

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
