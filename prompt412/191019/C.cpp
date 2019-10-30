#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>

std::vector<std::string> v[6];
std::map<std::string, bool> visited;

int main(void){
	int N, M;
	std::cin >> N >> M;
	for(int i=0; i<M; i++){
		std::string s;
		char c;
		std::cin >> s >> c;
		v[c-'a'].push_back(s);
	}
	std::queue<std::string> q;
	q.push("a");
	int ans = 0;
	while(!q.empty()){
		std::string now = q.front(); q.pop();
//		if(visited[now]) continue;
		if(now.length() == N){
			ans++;
			continue;
		}
		for(int i=0; i==0; i++){
			for(auto &s:v[now[i]-'a']){
				std::string to = now.substr(0, i) + s + now.substr(i+1);
//				std::cout << "test : " << to << '\n';
				if(!visited[to]) q.push(to), visited[to]=1;
			}
		}
	}
	std::cout << ans;
}
