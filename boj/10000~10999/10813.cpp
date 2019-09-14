#include<stdio.h>

int main(void){
	int N, M, a[101];
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) a[i]=i;
	while(M--){
		int x, y;
		scanf("%d %d", &x, &y);
		int temp = a[x];
		a[x] = a[y];
		a[y] = temp;
	}
	for(int i=1; i<=N; i++) printf("%d ",a[i]);
}
