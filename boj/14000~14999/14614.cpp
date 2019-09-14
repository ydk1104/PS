#include<stdio.h>

int main(void){
	int A, B;
	char C[101];
	scanf("%d %d", &A, &B);
	scanf("%s", &C);
	int i=0;
	for(;C[i]; i++);
	i--;
	if(C[i]%2) A^=B;
	printf("%d", A);
	}
