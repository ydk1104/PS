#include<stdio.h>
#include<stdlib.h>

typedef struct shape{
	int color;
	int size;
	int num;
}shape;

int player[200001];
shape ball[200001];
int sum[200001];
shape Queue[200001];
int cnt = 0;

void push(int color, int size){
	Queue[cnt].color = color;
	Queue[cnt++].size = size;
}

void pop(){
	sum[Queue[--cnt].color] += Queue[cnt].size;
	sum[0] += Queue[cnt].size;
}

int compare(const void *pa, const void *pb){
	shape* a = (shape*) pa;
	shape* b = (shape*) pb;
	if(a->size > b->size) return 1;
	return -1;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d %d", &ball[i].color, &ball[i].size);
		ball[i].num = i;
	}
	qsort(ball+1, N, sizeof(shape), compare);
	int now = 1;
	for(int i=1; i<=2000; i++){
		if(ball[now].size > i) i = ball[now].size;
		while(ball[now].size == i){
			player[ball[now].num] = sum[0] - sum[ball[now].color];
			push(ball[now].color, ball[now].size);
			now++;
		}
		while(cnt>0){
			pop();
		}
	}
	for(int i=1; i<=N; i++){
		printf("%d\n", player[i]);
	}
}
