#include<stdio.h>

int R(int N){
	int temp = 0;
	while(N>0){
		temp *= 10;
		temp += N%10;
		N /= 10;
	}
	return temp;
}

int main(void){
	int N;
	int cnt = 0;
	scanf("%d", &N);
	do{
		N += R(N);
		cnt++;
	}
	while((N != R(N)) && (N<10000) && cnt<3);
	if(N == R(N)){
		printf("%d", N);
	}
	else{
		printf("-1");
	}
	return 0;
}
