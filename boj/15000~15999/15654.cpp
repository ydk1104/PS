#include<stdio.h>
#include<algorithm>

int main(void){
	int N, M, a[10], check[10] = {0, };
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	std::sort(a, a+N);
	do{
		for(int i=0; i<M; i++) if(a[i]!=check[i]) goto v;
		continue;
		v:
		for(int i=0; i<M; i++){
			check[i] = a[i];
			printf("%d ", a[i]);
		}
		printf("\n");
	}while(std::next_permutation(a, a+N));
}
