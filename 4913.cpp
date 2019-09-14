#include<stdio.h>

int prime[1000001], prime2[1000001], isPrime[1000001], isPrime2[1000001], a, b;

int main(void){
	isPrime[2] = isPrime2[2] = 1;
	for(int i=3; i<=1000000; i+=2) isPrime[i] = 1;
	for(int i=3; i<=1000000; i+=2){
		if(!isPrime[i]) continue;
		for(int j=3; i*j<=1000000; j+=2){
			isPrime[i*j] = 0;
		}
		if(i%4==1) isPrime2[i] = 1;
	}
	for(int i=1; i<=1000000; i++) prime[i]=prime[i-1] + isPrime[i], prime2[i]=prime2[i-1] + isPrime2[i];
	while(scanf("%d %d",&a,&b),~a||~b){
		printf("%d %d ", a, b);
		if(a<1) a=1;
		if(b<1) b=1;
		printf("%d %d\n",prime[b]-prime[a-1], prime2[b]-prime2[a-1]);
	}
}
