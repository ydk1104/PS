#include<stdio.h>

int isPrime(int x){
	for(int i=2; i*i<=x; i++)
		if(x%i==0) return 0;
	return 1;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=N; i<=N+N/2; i++){
		if(isPrime(i)){
			printf("%d\n", i);
			i--;
			printf("%d %d\n", 1, N);
			for(int j=1; j<N; j++, i--) printf("%d %d\n", j, j+1);
			for(int j=1; j<N && i; j++, i--) printf("%d %d\n", j, N-j);
			break;
		}
	}
}
