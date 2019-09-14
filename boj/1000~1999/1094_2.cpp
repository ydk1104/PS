#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int cnt = 0;
	while(N>0){
		cnt += N%2;
		N/=2;
	}
	printf("%d", cnt);
}
