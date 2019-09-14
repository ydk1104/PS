#include<stdio.h>

char s[31];
int N, check[26];

int main(void){
	scanf("%d", &N);
	while(N--){
		scanf("%s", &s);
		check[s[0]-'a']++;
	}
	for(int i=0; i<26; i++) if(check[i]>4) printf("%c",i+'a'), N++;
	if(N==-1) printf("PREDAJA");
}
