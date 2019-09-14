#include<stdio.h>

int rev(int N){
	int temp=0;
	while(N>0){
		temp*=10;
		temp+=N%10;
		N/=10;
	}
	return temp;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	printf("%d", rev(rev(N)+rev(M)));
}
