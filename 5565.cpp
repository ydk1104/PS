#include<stdio.h>

int main(void){
	int sum;
	scanf("%d", &sum);
	for(int i=0; i<9; i++){
		int x;
		scanf("%d", &x);
		sum -= x;
	}
	printf("%d", sum);
}
