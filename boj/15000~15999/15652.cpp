#include<stdio.h>

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int a[7];
	for(int i=0; i<M; i++) a[i]=1;
	while(a[0] <= N){
		for(int i=0; i<M; i++) printf("%d ", a[i]);
		printf("\n");
		int j=M-1;
		a[j]++;
		while(a[j]>N && j>0){
			j--;
			a[j]++;
		}
		while(j<M-1){
			j++;
			a[j] = a[j-1];
		}
	}
}
