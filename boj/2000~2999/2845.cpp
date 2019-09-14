#include<stdio.h>

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int peo = N * M;
	int a[6];
	for(int i=1; i<=5; i++){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=5; i++){
		printf("%d ", a[i]-peo);
	}
}
