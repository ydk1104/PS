#include<stdio.h>
#define max(a,b) (a>b) ? a : b

int main(void){
	int N, M, T;
	scanf("%d %d %d", &N, &M, &T);
	int check[10001] = {0, };
	for(int i=1; i*N<=T; i++){
		check[i*N] = i;
	}
	for(int i=M; i<=T; i++){
		if(check[i-M] != 0 || i == M){
			check[i] = max(check[i], check[i-M]+1);
		}
	}
	int i = T;
	for(; check[i]==0 && i>0; i--){
	}
	printf("%d %d", check[i], T-i);
}
