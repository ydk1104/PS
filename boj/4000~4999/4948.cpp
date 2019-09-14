#include<stdio.h>
#define MAX 260000

int p[MAX+1];
int pcnt[MAX+1];

int main(void){
	pcnt[1] = 0;
	pcnt[2] = 1;
	for(int i=2; i<=MAX; i=i+2){
		p[i] = 1;
	}
	for(int i=3; i<=MAX; i++){
		if(p[i] == 0){
			for(int j=3; i*j<=MAX; j=j+2){
				p[i*j] = 1;
			}
			pcnt[i] = pcnt[i-1]+1;
		}
		else{
			pcnt[i] = pcnt[i-1];
		}
	}
	int N;
	scanf("%d", &N);
	while(N!=0){
		printf("%d\n", pcnt[2*N]-pcnt[N]);
		scanf("%d", &N);
	}
}
