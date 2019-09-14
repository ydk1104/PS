#include<stdio.h>

int ans, max;

int main(void){
	for(int i=0; i<5; i++){
		int sum = 0, x;
		for(int j=0; j<4; j++){
			scanf("%d", &x);
			sum += x;
		}
		if(sum>max){
			ans = i+1;
			max = sum;
		}
	}
	printf("%d %d", ans, max);
}
