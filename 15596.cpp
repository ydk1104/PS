#include<stdio.h>

long long sum(std::vector<int> &a){
	long long sum = 0;
	for(auto i:a) sum+=i;
	return sum;
}

int main(void){
}
