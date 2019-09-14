#include<stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

int cost[10001];
int pa[10001];
int sum;

int find(int x){
	if(pa[x] == x) return x;
	return pa[x] = find(pa[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if(x==y) return;
	if(cost[x] > cost[y]){
		int temp = x;
		x = y;
		y = temp;
	}
	sum -= cost[y];
	pa[y] = x;
}

int main(void){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for(int i=1; i<=N; i++){
		scanf("%d", &cost[i]);
		sum += cost[i];
		pa[i] = i;
	}
	for(int i=0; i<M; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	if(sum > K) printf("Oh no");
	else printf("%d", sum);
}
