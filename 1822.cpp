#include<stdio.h>
#include<set>
#include<vector>

int main(void){
	int N, M, x;
	std::set<int> s[2];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", &x);
		s[0].insert(x);
	}
	for(int i=0; i<M; i++){
		scanf("%d", &x);
		s[1].insert(x);
	}
	std::vector<int> ans;
	std::set<int>::iterator i=s[0].begin(), j=s[1].begin();
	for(; i!=s[0].end() && j!=s[1].end(); i++){
		while(j != s[1].end() && *i > *j) j++;
		if(*i == *j) j++;
		else ans.push_back(*i);
	}
	while(i != s[0].end()) ans.push_back(*i++);
	printf("%d\n", ans.size());
	for(auto &i : ans) printf("%d ", i);
}
