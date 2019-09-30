#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<char> v;

int main(void){
	long long N;
	scanf("%lld", &N);
//	N*=2;
	while(N){
		if(N%2) v.push_back('+');
		v.push_back('*');
		N/=2;
	}
	std::reverse(v.begin(), v.end());
	v.push_back('/');
	printf("%d\n", v.size());
	for(auto i:v) printf("[%c] ", i);
}
