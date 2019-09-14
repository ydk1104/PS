#include<stdio.h>

void print(int N){
	if(N==1){
		printf("#");
		return;
	}
	if(N==2){
		printf("##");
		return;
	}
	int i = 1;
	while(i*4<N) i*=2;
	int a,b;
	if(i*3<=N) a=i*2, b=N-a;
	else b=i, a=N-b;
	print(a); print(b);
	if(b==i) for(; b<i*2; b++) printf(".");
}

int main(void){
	int N;
	scanf("%d", &N);
	print(N);
}
