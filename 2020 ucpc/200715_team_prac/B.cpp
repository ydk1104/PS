#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

std::map<std::string, int> m;
std::vector<int> v[200001];
std::string mm[200001];
std::vector<std::string> ans;
bool visited[200010];

void dfs(int now, int prev){
	if(visited[now]) return;
	visited[now] = true;
	for(auto i : v[now]){
		ans.push_back(mm[i]);
		dfs(i, now);
	}
}

int main(void){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N;
	std::cin >> N;
	int cnt = 0;
	for(int i=0; i<N; i++){
		std::string in, x, out;
		std::cin >> in >> x >> out;
//		std::cout << "in : " << in << "\n" << "out : " << out << "\n";
		int a,b;
		if(m[in]) a = m[in];
		else a = m[in] = ++cnt, mm[a] = in;
		if(m[out]) b = m[out];
		else b = m[out] = ++cnt, mm[b] = out;		
//		std::cout << "a : " << a << "\n" << "b : " << b << "\n";
		v[a].push_back(b);
	}
	dfs(m["Baba"], -1);
	std::sort(ans.begin(), ans.end());
	std::string prev = "";
	for(auto i : ans){
		if(prev != i)std::cout << i << "\n";
		prev = i;
	}
}

dfs(1,3);
