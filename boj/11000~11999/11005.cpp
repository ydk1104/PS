#include<stdio.h>
#include<vector>
#include<algorithm>

int main(){
	int N, B;
	scanf("%d %d", &N, &B);
	std::vector<char> v;
	for(;N;N/=B){
		char temp = N%B;
		if(temp>9) temp+='A'-10;
		else temp+='0';
		v.push_back(temp);
	}
	std::reverse(v.begin(), v.end());
	for(auto i:v){
		printf("%c",i);
	}
}
