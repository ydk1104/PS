#include<stdio.h>
#include<vector>
#include<set>

std::set<char> set;

int main(void){
	int N;
	char s[501];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", &s);
		for(int j=0; s[j]; j++){
			if(s[j] != s[j+1]) set.insert(s[j]);
			else j++;
		}
		for(auto j:set) printf("%c",j);
		printf("\n");
		set.clear();
	}
}
