#include<stdio.h>

int main(void){
	char s[105];
	scanf("%s", &s);
	int ans = 0;
	for(int i=0; s[i]!=0; i++){
		if(s[i] != '-' && s[i]!= '='){
			ans++;
			if(s[i] == 'l' || s[i] == 'n'){
				if(s[i+1] == 'j') i++;
			}
			if(s[i] == 'd'){
				if(s[i+1] == 'z' && s[i+2] == '=') i++;
			}
		}
	}
	printf("%d", ans);
}
