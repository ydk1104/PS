#include<stdio.h>

int N;
char s[26][101];
int s_cnt[26];
int ans;
int test;

void BT(int now, int check){
	if(now==N){
		if(check == test)ans++;
		return;
	}
	BT(now+1, check|s_cnt[now]);
	BT(now+1, check);
}

int main(void){
	scanf("%d", &N);
	for(int i=0; i<26; i++) test |= 1<<i;
	for(int i=0; i<N; i++){
		scanf("%s", s[i]);
		for(int j=0; s[i][j]; j++) s_cnt[i] |= 1<<(s[i][j]-'a');
	}
	BT(0, 0);
	printf("%d",ans);
}
