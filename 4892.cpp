#include<stdio.h>

int cnt;
char s[2][5] = {"even", "odd"};

int main(void){
	int N;
	scanf("%d", &N);
	while(N){
		printf("%d. %s %d\n", ++cnt, s[N%2], N/2);
		scanf("%d", &N);
	}
}
