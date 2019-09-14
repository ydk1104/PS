#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int a=1, b=1;
	for(N--;N--;){
		if(b==1){
			b=a+1;
			a=1;
		}
		else b--, a++;
	}
	printf("%d %d", b, a);
}
