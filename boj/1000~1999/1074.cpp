#include<stdio.h>

int find(int N, int r, int c, int num){
	if(N==1){
		return num;
	}
	N = N>>1;
	if(r>=N){
		r = r-N;
		num += N*N*2;
	}
	if(c>=N){
		c = c-N;
		num += N*N;
	}
	return find(N, r, c, num);
}

int main(void){
	int N, r, c;
	scanf("%d %d %d", &N, &r, &c);
	N = 1<<N;
	printf("%d", find(N,r,c,0));
}
