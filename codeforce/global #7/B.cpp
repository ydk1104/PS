#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int max = 0;
	for(int i=0; i<N; i++){
		int a;
		scanf("%d", &a);
		printf("%d ", a+max);
		if(a>0) max = a+max;
	}
}
