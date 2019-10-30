#include<stdio.h>

int mod = 1e9+7;

void product(long long a[2][2], long long b[2][2]){ // a*=b;
	long long c[2][2] = {0,};
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<2; k++){
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= mod;
			}
		}
	}
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			a[i][j] = c[i][j];
		}
	}
}

int main(void){
	long long N;
	scanf("%lld", &N);
	if(!N){
		printf("0");
		return 0;
	}
	long long a[2][2] = {{1,0},{0,1}};
	long long b[2][2] = {{1,1},{1,0}};
	N--;
	while(N){
		if(N%2){
			product(a,b);
		}
		product(b,b);
		N/=2;
	}
	printf("%lld", a[0][0]);
}
