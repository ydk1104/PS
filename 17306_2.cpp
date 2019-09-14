#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

struct trie{
	trie* next[2];
	int cnt;
	int check;
};

int ans;

trie* make_trie(long long x, trie* now){
	if(x>1) now = make_trie(x/2, now);
	if(now->next[x%2] == NULL) now->next[x%2]=(trie*)calloc(sizeof(trie), 1), now->cnt++, ans++;
	return now->next[x%2];
}

int main(void){
	int N;
	scanf("%d", &N);
	trie *head = (trie *)calloc(sizeof(trie), 1);
	long long min = 1LL<<60;
	for(int i=0; i<N; i++){
		long long x;
		scanf("%lld", &x);
		min = std::min(min, x);
		trie *now = make_trie(x, head);
		now->check = 1;
	}
	trie *now = head;
	while(now->cnt==1 && now->check != 1){
		int next = 0;
		if(now->next[next] == NULL) next = 1;
		now = now->next[next];
		ans--;
	}
	printf("%d", ans+1);
}
