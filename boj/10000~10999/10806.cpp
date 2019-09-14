#include<stdio.h>

int V[100001];
int stack[100001];
int cnt;
void push(int x){
	stack[cnt++] = x;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	while(M--){
		int x, y;
		scanf("%d %d", &x, &y);
		V[x]++;
		V[y]++;
	}
	for(int i=1; i<=N; i++){
		if(V[i]==1) push(i);
	}
	if(cnt%2) push(1);
	printf("%d\n", cnt/2);
	for(int i=0; i<cnt/2; i++){
		printf("%d %d\n", stack[2*i], stack[2*i+1]);
	}
}
