#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for(; T>0; T--){
		int N;
		scanf("%d", &N);
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(i==1 || i==N || j==1 || j==N){
					printf("#");
				}
				else{
					printf("J");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}
