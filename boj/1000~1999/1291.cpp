#include<stdio.h>

int p[3000];
int cnt;

int digit(int N){
	int temp=0;
	while(N){
		temp+=N%10;
		N/=10;
	}
	return temp%2;
}

int im(int N){
	int count=0;
	for(int i=0; i<cnt; i++){
		if(N%p[i]) continue;
		count++;
		while(!(N%p[i])) N/=p[i];
	}
	return count%2;
	
}

int main(void){
	int N;
	scanf("%d", &N);
//	N=1;
//	while(N<2700){
	int prime[3000] = {0,};
	for(int i=4; i<=2700; i+=2) prime[i]=1;
	p[cnt++]=2;
	for(int i=3; i<=2700; i+=2){
		if(prime[i]) continue;
		for(int j=3; i*j<=2700; j+=2){
			prime[i*j]++;
		}
		p[cnt++]=i;
	}
	if(N>5 && digit(N) && !im(N)){
		printf("4");
	}
	else if(N==2 || N==4){
		printf("2");
	}
	else if(N>5 && digit(N)){
		printf("1");
	}
	else if(N!=1 && !im(N)){
		printf("2");
	}
	else{
		printf("3");
	}
	printf("\n");
//	N++;
}
