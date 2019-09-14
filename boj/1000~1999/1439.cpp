#include<stdio.h>

int main(void){
	char s[1000001];
	int cnt[2]={0,};
	scanf("%s", &s);
	for(int i=0; s[i];i++){
		cnt[s[i]-'0']++;
		while(s[i] == s[i+1]) i++;
	}
	printf("%d", cnt[0]>cnt[1] ? cnt[1] : cnt[0]);
}
