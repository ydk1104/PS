#include<stdio.h>
#include<vector>
#include<algorithm>

int dp[1000001][3];
char s[1000001];
std::vector<char> ans[2];

int main(void){
	scanf("%s",&s);
	int slen = 0;
	while(s[slen]) slen++;
	char *max = s+slen-1;
	char *l[3] = {s,s,s};
	char *r[3] = {max, max, max};
	while(l[0]<=r[0] || l[1]<=r[1] || l[2]<=r[2]){
		for(int i=0; i<3; i++){
			while(*l[i]!='a'+i && l[i]<=max) l[i]++;
			while(*r[i]!='a'+i && r[i]>=s) r[i]--;
		}
		int len=-1, tmp=-1;
		char *nl, *nr;
		for(int i=0; i<3; i++){
			if(len <= r[i] - l[i]) len=r[i]-l[i], nl=l[i], nr=r[i], tmp=i;
		}
		if(!(~tmp)) break;
		ans[0].push_back(tmp+'a');
		if(len) ans[1].push_back(tmp+'a');
		for(int i=0; i<3; i++){
			if(l[i] <= nl) l[i] = nl+1;
			if(r[i] >= nr) r[i] = nr-1;
		}
	}
	if(ans[0].size()+ans[1].size()<slen/2){
		printf("IMPOSSIBLE");
		return 0;
	}
	for(auto i:ans[0]) printf("%c",i);
	std::reverse(ans[1].begin(), ans[1].end());
	for(auto i:ans[1]) printf("%c",i);
}
