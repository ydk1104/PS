#include<stdio.h>

int c[31][31];

int nCr(int n, int r){
	if (c[n][r] != 0){
		return c[n][r];
	}
	if (r == 0 || r == n){
		c[n][r] = 1;
		return 1;
	}
	if (r == 1 || r == n-1){
		c[n][r] = n;
		return n;
	}
	c[n][r] = nCr(n-1,r-1) + nCr(n-1,r);
	return c[n][r];
}

int main(void){
	int T;
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", nCr(b,a));
	}
	return 0;
}
