#include<stdio.h>

int a = 100, b = 100;

void game(int x, int y){
	if(x>y) b-=x;
	if(y>x) a-=y;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		game(a, b);
	}
	printf("%d\n%d", a, b);
}
