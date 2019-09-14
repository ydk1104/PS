#include<stdio.h>

int main(void){
	int N, x;
	scanf("%d", &N);
	for(int i=0; i<N; i++){scanf("%d", &x); if(x==i+1) goto v;}
	printf("1000003");
	return 0;
	v:
		printf("-1");
}
