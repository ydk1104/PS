#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int a, b;
		scanf("%d,%d", &a, &b);
		printf("%d\n", a+b);
	}
}
