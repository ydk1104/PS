#include<stdio.h>
#include<algorithm>
#include<vector>

int main(void){
	int era[1001] = {1, 1, };
	std::vector<int> prime = {2};
	for(int i=4; i<=1000; i+=2) era[i] = 1;
	for(int i=3; i<=1000; i+=2){
		if(era[i]) continue;
		for(int j=3; i*j<=1000; j+=2){
			era[i*j] = 1;
		}
		prime.push_back(i);
	}
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		std::vector<int> ans;
		ans.push_back(3);
		N-=3;
		for(auto i:prime){
			if(!era[N-i]){
				ans.push_back(i);
				ans.push_back(N-i);
				break;
			}
		}
		std::sort(begin(ans), end(ans));
		for(auto i:ans) printf("%d ", i);
		printf("\n");
	}
}
