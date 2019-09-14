#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		std::map<std::string, int> m;
		for(int i=0; i<N; i++){
			std::string x;
			int y;
			std::cin >> x >> y;
			m[x] = m[x] + y;
		}
		std::string ans;
		int max=0;
		for(auto i:m){
			if(i.second > max){
				max = i.second;
				ans = i.first;
			}
		}
		std::cout << ans << '\n';
	}
}
