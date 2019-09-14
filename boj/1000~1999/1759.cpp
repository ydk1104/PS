#include<stdio.h>
#include<algorithm>
#include<vector>

char s[15];
char ans[15];
int N, M;

int check(char s[]){
	int vowels=0, consonants=0;
	for(int i=0; i<N; i++){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') vowels++;
		else consonants++;
	}
	if(vowels>0 && consonants>1) return 1;
	return 0;
}

void find(int now, int cnt, char ans[]){
	if(cnt==N && check(ans)){
		for(int i=0; i<N; i++) printf("%c", ans[i]);
		printf("\n");
		return;
	}
	if(now==M) return;
	ans[cnt]=s[now];
	find(now+1, cnt+1, ans);
	find(now+1, cnt, ans);
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++) scanf(" %c", &s[i]);
	std::sort(s, s+M);
	find(0, 0, std::vector<char> v(6));
}
