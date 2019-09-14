#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

char s[5001];
vector<string> v;

int main(void){
	scanf("%s", &s);
	for(int i=0; s[i]; i++) v.push_back(s+i);
	sort(v.begin(), v.end());
	int ans=0;
	for(auto p=v.begin()+1; p!=v.end(); p++){
		int row = 0;
		while((*p)[row] == (*(p-1))[row]) row++;
		ans = max(ans,row);
	}
	printf("%d", ans);
}
