#include<stdio.h>

int main(void){
	int sum=0, N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		sum += x;
	}
	if(sum*2>N) printf("Junhee is cute!");
	else printf("Junhee is not cute!");
}
