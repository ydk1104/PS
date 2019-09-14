#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for(;T--;){
		int N;
		scanf("%d", &N);
		printf("%d\n", (1<<N)-1);
	}
}
