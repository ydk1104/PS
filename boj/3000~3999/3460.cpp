#include<stdio.h>

void binary(int N){
	int a[20];
	int cnt = 0;
	while(N>0){
		a[cnt] = N&1;
		N = N>>1;
		cnt++;
	}
	for(int i=0; i<cnt; i++){
		if(a[i] == 1){
			printf("%d ", i);
		}
	}
	printf("\n");
}

int main(void){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int N;
		scanf("%d", &N);
		binary(N);
	}
}
