#include<stdio.h>
#include<vector>

int main(void){
	long long N;
	scanf("%lld", &N);
	long long temp = N;
	std::vector<long long> v;
	if(!(temp&1)){
		v.push_back(2);
		while(!(temp&1))temp = temp >> 1;
	}
	for(long long i=3; i*i<=temp; i+=2){
		if(temp%i) continue;
		while(!(temp%i)) temp/=i;
		v.push_back(i);
	}
	if(temp>1) v.push_back(temp);
	for(auto &i : v){
		N/=i;
		N*=(i-1);
	}
	printf("%lld", N);
}
