#include<stdio.h>

int check(char s[]){
	int check[30] = {0, };
	for(int i=0; s[i]!=0; i++){
		if(check[s[i]-'a'] != 0 && s[i-1] != s[i]) return 0;
		check[s[i]-'a']++;
	}
	return 1;
}

int main(void){
	int N, ans=0;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		char s[101];
		scanf("%s", &s);
		if(check(s)) ans++;
	}
	printf("%d", ans);
}
