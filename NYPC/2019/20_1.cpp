#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>

struct trie{
	trie* next[26];
	int cnt;
};

char s[1000001][301];
char q[200001];
long long dp[200001] = {1,};

int main(void){
	int N;
	trie *head = (trie*)calloc(sizeof(trie), 1);
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", &s[i]);
		trie *prev = head;
		for(int j=0; s[i][j]; j++){
			if(prev->next[s[i][j]-'A'] == NULL) prev->next[s[i][j]-'A'] = (trie*)calloc(sizeof(trie), 1);
			prev=prev->next[s[i][j]-'A'];
			if(s[i][j+1]==0) prev->cnt++;
		}
	}
	scanf("%s", &q);
	long long ans=0;
	long long mod = 1E9 + 7;
	trie *now = head;
	int i;
	for(i=0; q[i]; i++){
		trie *now = head;
		for(int j=i; q[j]; j++){
			if(now->next[q[j]-'A']==NULL) break;
			now=now->next[q[j]-'A'];
			dp[j+1] += dp[i] * now->cnt;
			dp[j+1] %= mod;
		}
	} // */
	printf("%lld",dp[i]);
}
