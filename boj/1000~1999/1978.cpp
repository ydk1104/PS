#include<stdio.h>

int prime(int N){
	if(N==1) return 0;
	for(int i=2; i*i<=N; i++){
		if(N%i==0){
			return 0;
		}
	}
	return 1;
}

int main(void){
	int N;
	int cnt = 0;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int a;
		scanf("%d", &a);
		cnt += prime(a);
	}
	printf("%d", cnt);
}
