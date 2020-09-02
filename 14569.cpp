#include<stdio.h>

int check[1001][51];
bool arr[10001][51];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int K;
		scanf("%d", &K);
		while(K--) scanf("%d", &check[i][K]);
	}
	int M;
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int K;
		scanf("%d", &K);
		while(K--){
			int x;
			scanf("%d", &x);
			arr[i][x] = true;
		}
	}
	int ans[10001] = {0,};
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			for(int k=0; check[i][k]; k++){
				if(!arr[j][check[i][k]]) goto v;
			}
			ans[j]++;
			v:;
		}
	}
	for(int i=0; i<M; i++) printf("%d\n", ans[i]);
}
