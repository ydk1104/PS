#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		long long int x, y;
		scanf("%I64d %I64d", &x, &y);
		printf("%I64d\n", x*9+y-9);
	}
}
