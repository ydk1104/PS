#include<stdio.h>
#include<vector>

const int MAX = 1e9;
bool NotPrime[100001];

int main(void){
	std::vector<int> prime(1,2);
	for(int i=3; i*i<=MAX; i+=2){
		if(NotPrime[i]) continue;
		for(int j=i*i; j<=100000; j+=2*i){
			NotPrime[j] = true;
		}
		prime.push_back(i);
	}
	long long N;
	while(~scanf("%lld", &N)){
		if(!N) break;
		long long temp = N;
		for(const auto& i : prime){
			if(i>=temp) break;
			if(temp%i) continue;
			while(!(temp%i)) temp /= i;
			N -= N/i;
		}
		if(temp>1) N -= N/temp;
		printf("%lld\n", N);
	}
}
