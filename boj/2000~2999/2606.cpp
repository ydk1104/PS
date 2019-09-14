#include<stdio.h>

int com[101][101];
int check[101];
int ans;
int Q[10001];
int end;
int start;

void push(int x){
	Q[end++] = x;
}

void BFS(){
	while(start!=end){
		int temp = Q[start++];
		if(check[temp]) continue;
		check[temp] = 1;
		ans++;
		for(int i=1; i<=com[temp][0]; i++){
			if(!check[com[temp][i]]) push(com[temp][i]);
		}
	}
}

int main(void){
	int N, M;
	scanf("%d\n%d", &N, &M);
	for(int i=1; i<=M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		com[a][++com[a][0]] = b;
		com[b][++com[b][0]] = a;
	}
	push(1);
	BFS();
	printf("%d", ans-1);
}
