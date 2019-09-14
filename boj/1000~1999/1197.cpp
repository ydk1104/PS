#include<stdio.h>
#include<stdlib.h>

typedef struct Edge{
	int x;
	int y;
	int c;
}Edge;

int vertex[10001];
Edge edge[100001];
int V, E;
int sum;

int compare(const void *pa, const void *pb){
	Edge *a = (Edge*) pa;
	Edge *b = (Edge*) pb;
	if(a->c > b->c) return 1;
	return -1;
}

int find(int x){
	if(vertex[x] == 0) return x;
	return vertex[x] = find(vertex[x]);
}

void merge(int a, int b, int cost){
	int ra = find(a);
	int rb = find(b);
	if(ra == rb) return;
	vertex[rb] = ra;
	sum += cost;
	V--;
	return;
}

int main(void){
	scanf("%d %d", &V, &E);
	for(int i=0; i<E; i++){
		scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].c);
	}
	qsort(edge, E, sizeof(Edge), compare);
	for(int i=0; V>1; i++){
		merge(edge[i].x, edge[i].y, edge[i].c);
	}
	printf("%d", sum);
}
