#include<stdio.h>

int check(long long N){
	int temp=0;
	while(N){
		temp+=N%10;
		N/=10;
	}
	return temp%2;
}

int main(void){
	int T;
	scanf("%d", &T);
	long long a1 = 1;
	for(int i=0; i<8; i++) a1*=10;
	long long a2 = a1*10-1;
	a1--;
	for(;T--;){
		long long N;
		scanf("%lld",&N);
		if(check(N*a1)) printf("%lld\n",N*a1);
		else printf("%lld\n",N*a2);
//		N=T;
//		printf("-1\n");
		v:;
	}
}
