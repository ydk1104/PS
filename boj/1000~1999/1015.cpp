#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int a[50];
	int b[50];
	for (int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	for (int i=0; i<N; i++){
		int tmp = 10000;
		int p;
		for (int j=0; j<N; j++){
			if (a[j] != 0){
				if (tmp > a[j]){
					tmp = a[j];
					p = j;
				}
			}
		}
		b[p] = i;
		a[p] = 0;
	}
	for (int i=0; i<N; i++){
		printf("%d ", b[i]);
	}
}
