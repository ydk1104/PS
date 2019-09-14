#include<stdio.h>

int main(void){
	int N, x, min, max;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &x);
		if(i==0){
			min = x;
			max = x;
		}
		else{
			min = (min < x) ? min : x;
			max = (max > x) ? max : x;
		}
	}
	printf("%d %d", min, max);
}
