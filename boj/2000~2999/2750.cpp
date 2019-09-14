#include<stdio.h>

int sort(int *a, int *b){
	if(*a > *b){
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

int main(void){
	int N;
	int a[1001];
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=N; i++){
		for(int j=i+1; j<=N; j++){
			sort(&a[i], &a[j]);
		}
		printf("%d\n", a[i]);
	}
}
