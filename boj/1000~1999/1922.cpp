#include<stdio.h>
#include<stdlib.h>

typedef struct edge{
	int a;
	int b;
	int cost;
}edge;

int com[1001];
edge v[100001];
int ans;
int N;

int find(int x){
	if(com[x] == 0) return x;
	return com[x] = find(com[x]);
}

void merge(int a, int b, int cost){
	int ra = find(a);
	int rb = find(b);
	if(ra==rb) return;
	ans += cost;
	N--;
	com[rb] = ra;
}

int compare(const void *pa, const void *pb){
	edge* a = (edge*) pa;
	edge* b = (edge*) pb;
	if(a->cost > b->cost) return 1;
	return -1;
}

int main(void){
	scanf("%d", &N);
	int M;
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[i].a = a;
		v[i].b = b;
		v[i].cost = c;
	}
	qsort(v, M, sizeof(edge), compare);
	for(int i=0; N>1; i++){
		merge(v[i].a, v[i].b, v[i].cost);
	}
	printf("%d", ans);
}
