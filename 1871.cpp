#include<stdio.h>

int main(void){
	int N;
	for(scanf("%d ", &N); N--;){
		char s[9];
		int r;
		scanf("%3c-%d ", s, &r);
		int l = (s[0]-'A') * 26 * 26 + (s[1]-'A') * 26 + (s[2]-'A');
		l -= r;
		bool flag = (l <= 100) && (l >= -100);
		puts(flag ? "nice" : "not nice");
	}
}
