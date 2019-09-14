#include<stdio.h>

int main(void){
	char s[101];
	scanf("%[^\n]s", &s);
	for(int i=0; s[i]!='\0'; i++){
		if((s[i]>='A') && s[i]<='A'+12){
			s[i] += 13;
		}
		else if((s[i]>='A'+13) && (s[i]<='A'+25)){
			s[i] -= 13;
		}
		if((s[i]>='a') && s[i]<='a'+12){
			s[i] += 13;
		}
		else if((s[i]>='a'+13) && (s[i]<='a'+25)){
			s[i] -= 13;
		}
	}
	printf("%s", s);
}
