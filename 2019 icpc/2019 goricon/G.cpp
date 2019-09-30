#include<stdio.h>

char s[1001];

int main(void){
	int N;
	scanf("%d", &N);
	scanf("%s", &s);
	for(int i=0; s[i]; i++){
		if(s[i]=='?' && s[N-i-1]=='?'){
			s[i] = s[N-i-1] = 'a';
		}
		else if(s[i]=='?'){
			s[i] = s[N-i-1];
		}
		else if(s[N-i-1]=='?'){
			s[N-i-1] = s[i];
		}
		else if(s[i]!=s[N-i-1]){
			while(1);
		}
	}
	printf("%s\n", s);
}
