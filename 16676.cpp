#include<stdio.h>

int log(int N){
	int cnt = 1;
	int max = 10;
	while(N>max){
		cnt++;
		max++;
		max *= 10;
	}
	return cnt;
}

int main(void){
	int N;
	scanf("%d", &N);
	printf("%d", log(N));
}
