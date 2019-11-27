#include<stdio.h>

void product(long long a[2][2], long long b[2][2], int mod){ // a*=b;
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
	long long T;
	scanf("%lld", &T);
	for(int t=1; t<=T; t++){
		long long a[2][2] = {{1,0},{0,1}};
		long long b[2][2] = {{1,1},{1,0}};
		int N, mod;
		scanf("%d %d", &N, &mod);
		N--;
		while(N){
			if(N%2){
				product(a,b,mod);
			}
			product(b,b,mod);
			N/=2;
		}
		printf("Case #%d: %lld\n", t, a[0][0]%mod);
	}
}
