#include<vector>
#include<stack>
#include<algorithm>
#include "hiccup.h"

int HicCup(std::string S) {
	int N = S.size();
	int stack = 0;
	int mark = 0;
	std::vector<std::pair<int, int> > v;
	std::vector<int> temp;
	int a[1000001] ={0,};
	for(int i=0; S[i]; i++){
		if(i) a[i] = a[i-1] + S[i]=='!';
	}
	mark = a[N-1];
	int left = 0, prev = 'H';
	for(int i=0; i<N; i++){
		if(S[i] == 'H') stack++;
		if(S[i] == 'C'){
			stack--;
			if(stack < 0) return -1;
			v.push_back({mark, stack});
		}
		if(S[i] == '!') mark--;
		if(S[i] == '!' && prev == 'H') return -1;
		prev = S[i];
	}
	std::stack<int> m;
	auto Prev = v.rbegin();
	for(auto &i:v.rbegin(); i != v.rend(); i++){
		if(i == v.rbegin()){
			continue;
		}
		if(i.second > Prev.second){
			m.push(Prev.first);
		}
		if(i.seocnd < Prev.second){
			m.pop();
		}
		if(i.second) i.first -= m.top();
	}
//	reverse(v.begin(), v.end());
	int N = v.size();
	while(left < right){
		int mid = (left+right)/2;
		int prev = v[0].first;
		for(int i=1; i<N; i++){
			prev = std::min(prev, i) - mid;
		}
		if(prev < 0) right = mid-1;
		left = mid+1;
	}
	int ans = 0;
	for(int mid=left-3; mid <= left+3; mid++){
		int prev = v[0].first;
		for(auto i:v){
			prev = std::min(prev, i) - mid;
		}
		if(prev < 0) break;
		ans = mid;
	}
	if(stack) return -1;
	return ans;
}
