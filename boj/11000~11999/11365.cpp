#include<stdio.h>
#include<string.h>

char s[501];

int main(void){
	while(strcmp(s, "END")){
		for(int i=strlen(s)-1; i>=0; i--) printf("%c", s[i]);
		if(s[0])printf("\n");
		scanf("%[^\n]s", &s);
		getchar();
	}
}
