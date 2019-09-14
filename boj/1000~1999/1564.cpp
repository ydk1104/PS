#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	long long ans=1;
	for(int i=2; i<=N; i++){
		ans*=i;
		while(!(ans%10)) ans/=10;
		ans%=1000000000000;
	}
	ans%=100000;
	printf("%05d", ans);
}
