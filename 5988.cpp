#include<stdio.h>

int main(void){
	int N;
	char ans[2][6] = {{"even"}, {"odd"}};
	for(scanf("%d", &N); N--;){
		char s[70];
		scanf("%s", &s);
		int len=0;
		while(s[len]) len++;
		printf("%s\n", ans[s[len-1]%2]);
	}
}
