#include<stdio.h>

int factorial(int N){
	if(N==0) return 1;
	if(N==1) return 1;
	return N * factorial(N-1);
}

int main(void){
	double e = 0;
	double n = 1;
	printf("n e\n");
	printf("- -----------\n");
	for(int i=0; i<=9; i++){
		e += n / factorial(i);
		if(i>2){
			printf("%d %.9f", i, e);			
		}
		else if(i==0){
			printf("%d 1", i);
		}
		else if(i==1){
			printf("%d 2", i);
		}
		else if(i==2){
			printf("%d 2.5", i);
		}
		if(i!=9){
			printf("\n");
		}
	}
}
