#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	double sum = 0;
	int max = 0;
	double ave;
	for(int i=1; i<=N; i++){
		int a;
		scanf("%d", &a);
		if(max<a){
			max = a;
		}
		sum += a;
	}
	ave = sum * 100 / max / N;
	printf("%f", ave);
}
