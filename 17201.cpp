#include<stdio.h>

int main(void){
	char s[11]={0,};
	gets(s);
	gets(s);
	int flag=0;
	char ans[2][5] = {"Yes", "No"};
	for(int i=1; s[i]; i++){
		if(s[i]==s[i-1]) flag=1;
	}
	puts(ans[flag]);
}
