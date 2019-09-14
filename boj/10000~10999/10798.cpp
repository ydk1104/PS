#include<stdio.h>

int main(void){
	char s[5][20] = {0, };
	for(int i=0; i<5; i++) scanf("%s", &s[i]);
	for(int i=0; i<15; i++){
		for(int j=0; j<5; j++){
			if(s[j][i]) printf("%c",s[j][i]);
		}
	}
}
