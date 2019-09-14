#include<stdio.h>

int main(void){
	int N, x, Y=0, M=0;
	scanf("%d", &N);
	while(N--){
		scanf("%d", &x);
		Y += ((x)/30+1)*10;
		M += ((x)/60+1)*15;
	}
	if(Y>M) printf("M"), Y=M;
	else if(Y==M) printf("Y M");
	else printf("Y");
	printf(" %d", Y);
}
