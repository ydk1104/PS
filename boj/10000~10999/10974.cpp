#include<stdio.h>
#include<algorithm>

int main(void){
	int N;
	scanf("%d", &N);
	int a[10];
	for(int i=1; i<=N; i++) a[i]=i;
	do{
		for(int i=1; i<=N; i++) printf("%d ", a[i]);
		printf("\n");
	}while(std::next_permutation(a+1, a+N+1));
}
