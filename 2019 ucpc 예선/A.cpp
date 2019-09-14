#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int arr[] = {2,1,2,3,4,5,4,3,2};
	printf("%d", arr[(N%8)]);
}
