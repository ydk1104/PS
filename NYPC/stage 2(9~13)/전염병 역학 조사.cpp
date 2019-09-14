#include<stdio.h>
#include<stdlib.h>

typedef struct meeting{
	int x;
	int y;
	int time;
}meeting;

meeting meet[1000000];
int stack[1000000];
int end;

void push(int x){
	stack[end++] = x;
}

int pop(void){
	if(end==0) return -1;
	return stack[--end];
}

int compare(const void *pa, const void *pb){
	meeting *a = (meeting*) pa;
	meeting *b = (meeting*) pb;
	return a->time>b->time;
}

int uf[1000000];

int find(int x){
	if(uf[x] == x) return x;
	return uf[x] = find(uf[x]);
}

void merge(int a, int b){
	int pa = find(a);
	int pb = find(b);
	if(pa==pb) return;
	if(pa<pb) uf[pb]=pa;
	else uf[pa]=pb;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		uf[i] = i;
	}
	for(int i=1; i<=M; i++){
		int x, y, t;
		scanf("%d %d %d", &meet[i].x, &meet[i].y, &meet[i].time);
	}
	qsort(meet+1, M, sizeof(meeting), compare);
	for(int i=1; i<=M; i++){
		int j;
		for(j=0; meet[i].time==meet[i+j].time; j++){
			push(meet[i+j].x);
			push(meet[i+j].y);
			merge(meet[i+j].x, meet[i+j].y);
		}
		i += j-1;
		int x;
		while((x = pop()) != -1){
			if(find(x) != 1) uf[x] = x;
		}
	}
	for(int i=1; i<=N; i++){
		if(uf[i]==1) printf("%d ", i);
	}
}
