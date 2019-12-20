#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> v;

using viter = std::vector<int>::iterator;

void f(viter l, viter r){
	if(l>=r) return;
	viter mid = std::lower_bound(l+1, r, *l);
	f(l+1, mid);
	f(mid, r);
	if(l < v.end()) std::cout << *l << '\n';
}

int main(void){
	int N;
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
	while(std::cin>>N) v.push_back(N);
	f(v.begin(), v.end());
}
