#include<stdio.h>
 
char s[1000001];
 
int main(void){
	scanf("%s", &s);
	for(int i=0; s[i]; i++){
		int sum=0;
		for(int j=0; s[i+j]&&j<=2; j++){
			sum += s[i+j];
		}
		if(sum == 82+66+76){
			printf("C");
			i+=2;
		}
		else{
			if(s[i]=='R') s[i]='S';
			if(s[i]=='B') s[i]='K';
			if(s[i]=='L') s[i]='H';
			printf("%c",s[i]);
		}
	}
}
