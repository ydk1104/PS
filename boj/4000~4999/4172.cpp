#include<stdio.h>
#include<math.h>

int x[1000001] = {1, };

int main(void){
	for(int i=1; i<=1000000; i++){
		x[i] = x[int(floor(i-sqrt(i)))] + x[int(floor(log(i)))] + x[int(floor(i*sin(i)*sin(i)))];
		x[i] %= 1000000;
	}
	int N;
	scanf("%d", &N);
	while(N!=-1){
		printf("%d\n", x[N]);
		scanf("%d", &N);
	}
}
