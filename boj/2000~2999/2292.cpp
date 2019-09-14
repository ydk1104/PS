#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	if(N==1) printf("1");
	else{
		int i=0;
		while(i*(i+1)*3+1<N) i++;
		printf("%d", i+1);
	}
}
