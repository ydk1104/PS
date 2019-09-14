#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int a[10001] = {0, };
	int b;
	for(int i=1; i<=N; i++){
		scanf("%d", &b);
		a[b]++;
	}
	for(int i=0; i<=10000; i++){
		for(int j=1; j<=a[i]; j++){
			printf("%d\n", i);
		}
	}
}
