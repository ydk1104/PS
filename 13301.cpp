#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	long long int fi[83];
	fi[1] = fi[2] = 1;
	for(int i=3; i<=N+2; i++){
		fi[i] = fi[i-1] + fi[i-2];
	}
	
	printf("%lld", 2*fi[N+2]);
}
