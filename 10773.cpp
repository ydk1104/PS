#include<stdio.h>
#include<vector>

std::vector<int> v;

int main(void){
	int N;
	scanf("%d", &N);
	while(N--){
		int x;
		scanf("%d", &x);
		if(x) v.push_back(x);
		else v.pop_back();
	}
	long long ans=0;
	for(auto i:v) ans+=i;
	printf("%lld",ans);
}
