#include<stdio.h>

int main(void){
	int K, D1, D2;
	scanf("%d %d %d", &K, &D1, &D2);
	double h = (K*K) - double(D1-D2)*(D1-D2)/4;
	printf("%f", h);
} 
