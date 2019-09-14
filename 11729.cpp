#include<stdio.h>

void move(int N, int from, int to){
	if(!N) return;
	move(N-1, from, 6-from-to);
	printf("%d %d\n", from, to);
	move(N-1, 6-from-to, to);
}

int main(void){
	int N;
	scanf("%d", &N);
	printf("%d\n", (1<<N)-1);
	move(N, 1, 3);
}
