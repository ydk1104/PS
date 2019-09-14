#include<stdio.h>

char s[1000001];
char ans[500001];
int p[3] = {4, 2, 1};

int main(void){
	scanf("%s", s);
	int len = 0;
	while(s[len]) len++;
	len%=3;
	if(!len) len=3;
	for(int i=0; s[i]; i++){
		if(!ans[(i+3-len)/3]) ans[(i+3-len)/3]+='0';
		ans[(i+3-len)/3] += (s[i]-'0')*p[(i+3-len)%3];
	}
	printf("%s", ans);
}
