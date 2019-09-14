#include<stdio.h>
#include<string.h>

int main(void){
	int N;
	char s[51][51] = {0, };
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%s", &s[i]);
		if(i==1) strcpy(s[0], s[1]);
	}
	for(int i=2; i<=N; i++){
		for(int j=0; s[i][j] != '\0'; j++){
			if(s[0][j] != s[i][j]){
				s[0][j] = '?';
			}
		}
	}
	printf("%s", s[0]);
}
