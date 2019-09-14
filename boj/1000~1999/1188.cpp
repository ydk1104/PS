#include<stdio.h>

int gcd(int x, int y){return y?gcd(y,x%y):x;}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	printf("%d", M-gcd(N,M));
}
