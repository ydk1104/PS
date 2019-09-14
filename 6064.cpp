#include<stdio.h>

int check(int N, int M, int x, int y){
	int i = x-y;
	for(; i<=N*M && i%M!=0; i+=N){}
	if(i>N*M) return -1;
	return i+y;
}

int main(void){
	int T, N, M, x, y;
	scanf("%d", &T);
	for(; T>0; T--){
		scanf("%d %d %d %d", &N, &M, &x, &y);
		printf("%d\n", check(N, M, x, y));
	}
}
