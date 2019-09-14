#include<stdio.h>
#define MAX 7500000

int era[MAX+1];
int prime[1000000];
int cnt;

int main(void){
	int K;
	scanf("%d", &K);
	prime[cnt++] = 2;
	for(int i=3; cnt<K; i+=2){
		if(era[i]) continue;
		for(int j=3; i*j<MAX; j+=2){
			era[i*j] = 1;
		}
		prime[cnt++] = i;
	}
	printf("%d\n", prime[K-1]);
}
