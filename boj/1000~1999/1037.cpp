#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int max, min;
	scanf("%d", &max);
	min = max;
	for (int i=1; i<N; i++){
		int temp;
		scanf("%d", &temp);
		if(max<temp) max=temp;
		if(min>temp) min=temp;
	}
	printf("%d", min*max);
}
