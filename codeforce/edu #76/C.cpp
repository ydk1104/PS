#include<stdio.h>

int check[200001];

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		int ans = -1;
		for(int i=1; i<=N; i++){
			check[i] = 0;
		}
		for(int i=1; i<=N; i++){
			int x;
			scanf("%d", &x);
			if(check[x] && (ans==-1 || ans > i-check[x]+1)) ans = i-check[x]+1;
			check[x] = i;
		}
		printf("%d\n", ans);
	}
}
