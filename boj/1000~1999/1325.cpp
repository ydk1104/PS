#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b) ? (a) : (b))

typedef struct computer{
	int num;
	computer* next;
}com;

com* C;
int Chack[10001];

void push(int x, int num){
	com* temp = (com*)malloc(sizeof(com*));
	com* i = C+x;
	while(i->next != NULL){
		i = i->next;
	}
	i->next = temp;
	temp->num = num;
}

int DFS(int *a, int x, int cnt){
	if(Chack[x] != 0) return Chack[x];
	int ans = 1;
	com* temp = C+x;
	while(temp->next != NULL){
		if(temp->next)
		cnt += DFS(a, temp->next->num, cnt+1);
	}
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	C = (com*)calloc(N+1, sizeof(com*));
	for(int i=1; i<=M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		push(b, a);
	}
	int check[10001] = {0, };
	for(int i=1; i<=N; i++){
		MAX = max(MAX, DFS(ans, i, 1));
		for()
	}
}
