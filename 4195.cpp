#include<iostream>
#include<string>
#include<map>
#include<vector>

std::string& find(std::string& x, std::map<std::string, std::string>& pa){
	if(x == pa[x]) return x;
	return pa[x] = find(pa[x], pa);
}

int main(void){
	int T;
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	for(std::cin >> T; T--;){
		std::map<std::string, int> cnt;
		std::map<std::string, std::string> pa;
		int N;
		std::cin >> N;
		while(N--){
			std::string x,y;
			std::cin >> x >> y;
			if(pa.find(x)==pa.end()) pa[x] = x, cnt[x] = 1;
			if(pa.find(y)==pa.end()) pa[y] = y, cnt[y] = 1;
			x = find(x, pa); y = find(y, pa);
			if(x != y) pa[y] = x, cnt[x] += cnt[y];
			std::cout << cnt[x] << '\n';
		}
	}
}
