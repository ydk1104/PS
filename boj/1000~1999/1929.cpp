#include<stdio.h>

int PN[1000001] = {1, 1, };

int main(void){
	int M, N;
	scanf("%d %d", &M, &N);
	for(int i=4; i<=N; i+=2){
		PN[i] = 1;
	}
	for(int i=3; i<=N; i+=2){
		if(PN[i] == 0){
			for(int j=3; i*j<=N; j+=2){
				PN[i*j] = 1;
			}
		}
	}
	for(int i=M; i<=N; i++){
		if(PN[i]==0){
			printf("%d\n", i);
		}
	}
}
