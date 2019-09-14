#include<stdio.h>

int main(void){
	char s[100001], _key[100001], *key=_key;
	scanf("%s\n%s", s, _key);
	for(int i=0, j=0; s[i]; i++, j++){
		if(!key[j]){
			j=0;
			key = s;
		}
		s[i] -= key[j]-'A';
		if(s[i] < 'A') s[i]+=26;
	}
	printf("%s",s);
}
