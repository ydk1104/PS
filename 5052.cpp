#include<stdio.h>
#include<stdlib.h>

struct trie{
	trie *next[10];
	int value;
};

char s[10001][11];

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		trie *head = (trie*)calloc(sizeof(trie), 1);
		int N;
		scanf("%d", &N);
		int i;
		for(i=0; i<N; i++){
			scanf("%s", &s[i]);
			trie *prev = head;
			for(int j=0; s[i][j]; j++){
				if(prev->next[s[i][j]-'0'] == NULL) prev->next[s[i][j]-'0'] = (trie*)calloc(sizeof(trie), 1);
				else if(!(s[i][j+1]) || prev->next[s[i][j]-'0']->value){
					printf("NO\n");
					goto v;
				}
				prev = prev->next[s[i][j]-'0'];
			}
			prev->value = 1;
		}
		printf("YES\n");
		v:;
		while(++i<N) scanf("%s", &s[i]);
	}
}
