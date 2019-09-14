#include<stdio.h>

char aeiou[] = {'a', 'e', 'i', 'o', 'u'};

int check(char x){
	for(int i=0; i<5; i++){
		if(x == aeiou[i]) return 1;
	}
	return 0;
}

int main(void){
	char s[101];
	scanf("%s", &s);
	int ans=0;
	for(int i=0; s[i]; i++) ans += check(s[i]);
	printf("%d", ans);
}
