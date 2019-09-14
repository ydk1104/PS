#include<stdio.h>

int toi(char *s, int N){
	char *p = s;
	int temp=0;
	while(*p) temp*=N, temp+=*p<'a'?*p-'0':*p-'a'+10, p++;
	return temp;
}

int main(void){
	char s[20];
	int ans;
	scanf("%s", &s);
	if(*s=='0'){
		if(s[1]=='x') ans=toi(s+2, 16);
		else ans=toi(s+1, 8);
	}
	else ans=toi(s, 10);
	printf("%d",ans);
}
