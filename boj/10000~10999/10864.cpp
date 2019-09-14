#include<stdio.h>

int main(void){
	int N, M;
	int ans[1001]= {0,};
	scanf("%d %d", &N, &M);
	for(int i=1; i<=M; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		ans[x]++;
		ans[y]++;
	}
	for(int i=1; i<=N; i++) printf("%d\n",ans[i]);
}
