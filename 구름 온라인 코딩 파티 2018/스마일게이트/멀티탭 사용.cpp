#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int sum = 1-N;
	for(int i=1; i<=N; i++){
		int temp;
		scanf("%d", &temp);
		sum += temp;
	}
	printf("%d", sum);
}
