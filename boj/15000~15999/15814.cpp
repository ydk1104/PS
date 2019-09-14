#include<stdio.h>

int main(void){
	char s[201];
	scanf("%s", &s);
	int T;
	scanf("%d", &T);
	while(T--){
		int x, y;
		scanf("%d %d", &x, &y);
		char temp = s[x];
		s[x] = s[y];
		s[y] = temp;
	}
	printf("%s",s);
}
