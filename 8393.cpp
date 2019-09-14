#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int cnt = 0;
	for(int i=1; i<=N; i++){
		cnt += i;
	}
	printf("%d", cnt);
}
