#include<stdio.h>

int main(void){
	int N, a[100001];
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d", &x);
		a[x] = x-i;
	}
	for(int i=1; i<=N; i++) printf("%d ",a[i]);
}
