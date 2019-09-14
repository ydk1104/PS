#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int cnt=1;
	while(N>1){
		if(N%2) N=3*N+1;
		else N/=2;
		cnt++;
	}
	printf("%d",cnt);
}
