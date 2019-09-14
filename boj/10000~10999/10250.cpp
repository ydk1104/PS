#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int H, W, N;
		scanf("%d %d %d", &H, &W, &N);
		int room = N%H*100 + N/H+1;
		if(N%H == 0){
			room += H*100;
			room --;
		}
		printf("%d\n", room);
	}
}
