#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>

struct trie{
	trie* next[26];
	trie* fail;
	std::vector<int> cnt;
	std::vector<trie*> other;
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
			if(s[i][j+1]==0)prev->cnt.push_back(j+1);
		}
	}
	std::queue<trie*> Q;
	head->fail = head;
	Q.push(head);
	while(!Q.empty()){
		auto now = Q.front(); Q.pop();
		for(int i=0; i<26; i++){
			auto next = now->next[i];
			if(!next) continue;
			if(now == head) next->fail = head;
			else{
				auto temp = now->fail;
				while(temp != head && !temp->next[i]) temp = temp->fail;
				if(temp->next[i]) temp = temp->next[i];
				next->fail = temp;
			}
			if(next->fail) next->other.push_back(next->fail);
			Q.push(next);
		}
	}
	scanf("%s", &q);
	long long ans=0;
	long long mod = 1E9 + 7;
	trie *now = head;
	int i;
	for(i=0; q[i]; i++){
		while(now != head && !now->next[q[i]-'A']) now = now->fail;
		if(now->next[q[i]-'A']) now=now->next[q[i]-'A'];
		Q.push(now);
		while(!Q.empty()){
			auto now = Q.front(); Q.pop();
			for(auto j:now->cnt) dp[i+1] += dp[i-j+1], dp[i]%=mod;
			for(auto j:now->other) Q.push(j);
		}
	}
/*	for(i=0; q[i]; i++){
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
