#include<stdio.h>

int hansu(int N){
	if(N<100){
		return 1;
	}
	else{
		int a = N/100;
		int b = (N/10)%10;
		int c = N%10;
		if(a-b == b-c){
			return 1;
		}
		else{
			return 0;
		}
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	int cnt = 0;
	for(int i=1; i<=N; i++){
		cnt += hansu(i);
	}
	printf("%d", cnt);
}
