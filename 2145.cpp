#include<stdio.h>

int sum(int N){
	int temp = 0;
	while(N){
		temp += N%10;
		N/=10;
	}
	if(temp > 9) temp = sum(temp);
	return temp;
}

int main(void){
	int N;
	scanf("%d", &N);
	while(N){
		printf("%d\n", sum(N));
		scanf("%d", &N);
	}
}
