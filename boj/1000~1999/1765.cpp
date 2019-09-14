#include<stdio.h>

int pa[1001];
int e[1001][1001];
int cnt;

int find(int x){
	if(pa[x] == x) return x;
	return pa[x] = find(pa[x]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	cnt--;
	pa[b] = a;
}

int main(void){
	int N, M;
	scanf("%d\n%d", &N, &M);
	cnt=N;
	for(int i=1; i<=N; i++) pa[i] = i;
	for(int i=0; i<M; i++){
		char x;
		int a, b;
		scanf("\n%c %d %d", &x, &a, &b);
		if(x=='F'){
			merge(a, b);
		}
		else{
			e[a][b] = 1;
			e[b][a] = 1;
			for(int i=1; i<=N; i++){
				if(e[a][i]) merge(b, i);
				if(e[b][i]) merge(a, i);
			}
		}
	}
	printf("%d", cnt);
}
