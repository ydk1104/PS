#include<stdio.h>

int main(void){
	double N;
	long long int ans_x=0, ans_y=0;
	scanf("%lf", &N);
	for(int i=1; i<=N; i++){
		long long int x, y;
		scanf("%lld %lld", &x, &y);
		ans_x += x;
		ans_y += y;
	}
	printf("%lf %lf", ans_x/N, ans_y/N);
	return 0;
}
