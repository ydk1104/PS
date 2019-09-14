#include<stdio.h>
#include<algorithm>

struct Edge{
	int x, y, cost;
	void scan(){
		scanf("%d %d %d", &x, &y, &cost);
	}
	bool operator <(const Edge &x){
		return this->cost < x.cost;
	}
}edge[200001];

int pa[200001];

int find(int x){
	if(pa[x]==x) return x;
	return pa[x] = find(pa[x]);
}

void merge(int x, int y, int cost, int *N, int *ans){
	x = find(x); y = find(y);
	if(x==y) return;
	pa[y] = x;
	(*N)--;
	(*ans)+=cost;
}

int main(void){
	int N, M;
	do{
		scanf("%d %d", &N, &M);
		if(!N) break;
		for(int i=0; i<N; i++) pa[i] = i;
		int sum=0;
		for(int i=0; i<M; i++){
			edge[i].scan();
			sum += edge[i].cost;
		}
		int ans=0;
		std::sort(edge, edge+M);
		N--;
		for(int i=0; N; i++){
			merge(edge[i].x, edge[i].y, edge[i].cost, &N, &ans);
		}
		printf("%d\n", sum-ans);
	}while(1);
}
