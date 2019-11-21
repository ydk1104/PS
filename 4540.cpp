#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int T;
	std::cin >> T;
	while(T--){
		int N, M;
		std::cin >> N >> M;
		std::vector<std::string> v;
		for(int i=0; i<N; i++){
			std::string temp;
			std::cin >> temp;
			v.push_back(temp);
		}
		std::vector<std::pair<std::string, int> > v2(0);
		int check[20] = {0, }, min=0;
		for(int i=0; i<M; i++){
			int x, y;
			std::cin >> x >> y;
			x--; y--;
			v2.push_back({v[x], y});
			v[x] = std::string();
			check[y] = 1;
		}
		int now = 0;
		for(int i=M; i<N; i++){
			while(check[min]) min++;
			while(v[now]=="") now++;
			v2.push_back({v[now], min});
			now++; min++;
		}
		std::sort(v2.begin(), v2.end(), [](const auto& x, const auto& y){
			return x.second < y.second;
		});
		int prev = 1;
		for(const auto& i:v2) std::cout << i.first << ' ';
		std::cout << '\n';
	}
}
