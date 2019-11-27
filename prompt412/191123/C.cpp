#include<stdio.h>

int pa[10001];
int ans;

int find(int x){return x==pa[x] ? x : pa[x]=find(pa[x]);}
int merge(int x, int y){
	x = find(x); y = find(y);
	if(x != y) pa[y] = x, ans--;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		pa[i] = i;
	}
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d", &x);
		merge(i,x);
	}
	printf("%d", N+ans);
}
