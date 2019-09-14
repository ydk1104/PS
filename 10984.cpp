#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for(;T--;){
		int N;
		scanf("%d", &N);
		double cnt=0, sum=0, x,y;
		for(;N--;){
			scanf("%lf %lf", &x, &y);
			cnt += x;
			sum += x*y;
		}
		printf("%.0f %f\n", cnt, sum/cnt);
	}
}
