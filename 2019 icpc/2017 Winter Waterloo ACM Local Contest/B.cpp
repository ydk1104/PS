#include<stdio.h>
#include<vector>
#include<algorithm>

char s[2001];
int dp[2020][2020];
int max[2020];
int cnt[26];

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	scanf("%s", &s);
	for(int i=0; s[i]; i++){
//		dp[i+1][s[i]] = max[i]+1;
//		max[i+1] = std::max(max[i+1], dp[i+1][s[i]]);
		cnt[s[i]-'a']++;
	}
	int min = N+1, minchar;
	for(int i=0; i<26; i++){
		if(min > cnt[i]) min = cnt[i], minchar = i+'a';
	}
	if(min > K || N < K){
		printf("WRONGANSWER");
		return 0;
	}
	K-=min;
	std::vector<char> ans;
	for(int i=0; s[i]; i++){
		if(s[i] == minchar) ans.push_back(s[i]);
		else if(K) ans.push_back(s[i]), K--;
	}
	while(ans.size()<N) ans.push_back(minchar);
	for(auto i:ans) printf("%c",i);
}
