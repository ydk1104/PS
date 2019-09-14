#include<stdio.h>
#define INT 10000000

int check[2*INT+1];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d", &x);
		check[x+INT]++;
	}
	int M;
	scanf("%d", &M);
	for(int i=1; i<=M; i++){
		int x;
		scanf("%d", &x);
		printf("%d ", check[x+INT]);
	}
}
