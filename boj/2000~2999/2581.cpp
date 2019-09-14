#include<stdio.h>

int main(void){
	int a[10001] = {1, 1, };
	for(int i=2; i*i<=10000; i++){
		if(a[i] == 0){
			for(int j=2; i*j<=10000; j++){
				a[i*j] = 1;
			}
		}
	}
	int M, N;
	scanf("%d %d", &M, &N);
	int min = 0;
	int sum = 0;
	for(int i=M; i<=N; i++){
		if(a[i] ==0){
			sum += i;
			if(min == 0){
				min = i;
			}
		}
	}
	if(min == 0){
		printf("-1");		
	}
	else{
		printf("%d\n%d", sum, min);	
	}
}
