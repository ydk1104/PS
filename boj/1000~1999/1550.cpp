#include<stdio.h>

int f(char x){
	if(x>='A') return x-'A'+10;
	return x-'0';
}

int main(void){
	char s[7];
	scanf("%s", &s);
	int i=0;
	while(s[i]) i++;
	i--;
	int ans=0;
	for(int j=1; i>=0; i--, j*=16){
		ans += j*f(s[i]);
	}
	printf("%d", ans);
}
