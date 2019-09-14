#include<stdio.h>

long long int p[1000001];
long long int prime[10000000];


int main(void){
	long long int min, max;
	scanf("%lld %lld", &min, &max);
	for (long long int i=2; i*i<=max; i++){
		p[i] = 1;
	}
	long long int cnt = 0;
	for (long long int i=2; i*i<=max; i++){
		if (p[i]==1){
			for (long long int j=2; i*j*i*j<=max; j++){
				p[i*j] = 0;
			}
			prime[cnt] = i*i;
			cnt++;
		}
	}
	long long int d = max-min;
	for (long long int i=0; i<=d; i++){
		p[i] = 1;
	}
	for (long long int i=0; i<cnt; i++){
		long long int start = min / prime[i];
		if (min % prime[i] != 0){
			start++;
		}
		start = start * prime[i];
		start = start - min;
		while (start<=d && start>=0){
			p[start] = 0;
			start += prime[i];
		}
	}
	cnt = 0;
	for (long long int i=0; i<=d; i++){
		cnt += p[i];
	}
	printf("%lld\n", cnt);
	return 0;
}
