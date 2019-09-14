#include<stdio.h>

int main(void){
	int T;
	char ans[2][4] = {"No", "Yes"};
	for(scanf("%d", &T), getchar(); T--;){
		char s[10001];
		gets(s);
		int slen = 0;
		while(s[slen]){
			if(s[slen]>='a' && s[slen]<='z') s[slen]-=32;
			slen++;
		}
		int type=1;
		for(int i=0; i<slen; i++){
			if(s[i]!=s[slen-1-i]) type=0;
		}
		puts(ans[type]);
	}
}
