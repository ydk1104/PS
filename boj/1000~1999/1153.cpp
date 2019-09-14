#include<stdio.h>
#define MAX 1000000

int era[MAX+1], prime[MAX+1];

int main(void){
	int now=0;
	for(int i=3; i<=MAX; i+=2){
		if(era[i]) continue;
		for(int j=3; i*j<=MAX; j+=2){
			era[i*j] = 1;
		}
		prime[now++] = i;
	}
	int N;
	scanf("%d", &N);
	if(N<8){
		printf("-1");
	}
	else if(N==9){
		printf("2 2 2 3");
	}
	else{
		printf("%d %d ", 2, 2+N%2);
		N -= 4;
		N -= N%2;
		for(int j=0; j<now; j++){
			if(era[N-prime[j]] == 0){
				printf("%d %d", prime[j], N-prime[j]);
				break;
			}
		}
	}
}
