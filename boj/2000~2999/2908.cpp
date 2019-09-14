#include<stdio.h>

int max(int a, int b){
	int temp = 0;
	while(a>0){
		temp *= 10;
		temp += a%10;
		a /= 10;
	}
	a = temp;
	temp = 0;
	while(b>0){
		temp *= 10;
		temp += b%10;
		b /= 10;
	}
	b = temp;
	if(a>b) return a;
	return b;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	printf("%d", max(N, M));
}
