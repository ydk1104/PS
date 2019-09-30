#include<stdio.h>

long long arr[15];
long long x=1, y=1;

long long cal(int N){
	if(!N) return 0;
	x^=y; y^=x; x^=y;
//	printf("%lld %lld %lld\n", x,y);
	x += y*arr[N-1];
	cal(N-1);
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
	}
	x=arr[N-1];
	cal(N-1);
	x^=y; y^=x; x^=y;
	printf("%lld %lld", y-x, y);
}
