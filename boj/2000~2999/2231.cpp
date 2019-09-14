#include<stdio.h>

int sum(int x){
	int sum1 = x;
	while(x>0){
		sum1 += x%10;
		x /= 10;
	}
	return sum1;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		if(N==sum(i)){
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
	return 0;
}
