#include<stdio.h>

int main(void){
	char s[20];
	scanf("%s", &s);
	int time = 0;
	for(int i=0; s[i]!='\0'; i++){
		if(s[i]<'S'){
			time += (s[i]-'A')/3+3;
		}
		else if(s[i] == 'S'){
			time += 8;
		}
		else if(s[i]<='V'){
			time += 9;
		}
		else if(s[i]<='Z'){
			time += 10;
		}
	}
	printf("%d", time);
}
