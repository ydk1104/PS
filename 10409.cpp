#include<stdio.h>

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d",&x);
		M-=x;
		if(M<0){
			printf("%d",i);
			goto v;
		}
	}
	printf("%d",N);
	v:;
}
