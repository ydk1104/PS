#include<stdio.h>

int main(void){
	int N, P;
	int check[1001] = {0, };
	scanf("%d %d", &N, &P);
	int cnt = 1;
	int i = N;
	do{
		check[i] = cnt;
		i = (i * N) % P;
		cnt++;
	}
	while(!check[i]);
	printf("%d", cnt-check[i]);
}
