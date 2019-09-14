#include<stdio.h>

int main(void){
	int N;
	int check[10102];
	scanf("%d", &N);
	for(int i=1; i<=100; i++){
		check[i*i+i+1] = i;
	}
	printf("%d", check[N]);
}
