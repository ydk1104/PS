#include<stdio.h>

const int MAX = 45000;

long long m[MAX+1];

int go(long long N){
	int temp = 0;
	for(long long i=1; i*i<=N; i++) temp += m[i] * (N/(i*i));
	return temp;
}

int main(void){
	long long N;
	scanf("%d", &N);
	for(int i=1; i<=MAX; i++) m[i] = 1;
	for(int i=2; i<=MAX; i++){
		if(m[i] != 1) continue;
		for(int j=i; j<=MAX; j+=i) m[j] *= -i;
		for(int j=i*i; j<=MAX; j+=i*i) m[j] = 0;
	}
	for(int i=2; i<=MAX; i++){
		if(m[i] > 0 ) m[i] = 1;
		if(m[i] < 0) m[i] = -1;
	}
	long long l=1, r=2e9;
	while(l<=r){
		long long mid = (l+r)/2;
		if(go(mid)==N && go(mid-1)<N){
			printf("%d", mid);
			break;
		}
		else if(go(mid)>=N) r = mid;
		else l = mid;
	}
}
