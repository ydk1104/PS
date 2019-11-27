#include<stdio.h>

int main(void){
	char s[51];
	scanf("%s", &s);
	int ans=0, now=0, c=1;
	for(int i=0; s[i]; i++){
		if(s[i]=='+'){
			ans += now * c;
			now = 0;
			continue;
		}
		if(s[i]=='-'){
			ans += now * c;
			now = 0;
			c = -1;
			continue;
		}
		now *= 10;
		now += s[i]-'0';
	}
	printf("%d",ans+now*c);
}
