#include<stdio.h>

int main(void){
	int a[15] = {0, };
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	for (int i=1; i<=10; i++){
		a[i+3] = a[i] + a[i+1] + a[i+2];
	}
	int T;
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
		int N;
		scanf("%d", &N);
		printf("%d\n", a[N]);
	}	
}
