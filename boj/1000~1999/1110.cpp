#include<stdio.h>

int main(void){
	int N, N0;
	scanf("%d", &N);
	N0 = N;
	int cnt = 0;
	do{
		N = ((N % 10 + N / 10) % 10) + N % 10 * 10;
		cnt++;
	}
	while(N!=N0);
	printf("%d", cnt);
}
