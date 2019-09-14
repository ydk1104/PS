#include<stdio.h>

int fac_0_cnt(int N){
	int cnt = 0;
	while(N>0){
		cnt += N/5;
		N /= 5;
	}
	return cnt;
}

int main(void){
	int T;
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
		int N;
		scanf("%d", &N);
		printf("%d\n", fac_0_cnt(N));
	}
}
