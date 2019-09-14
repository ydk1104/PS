#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int N;
		scanf("%d", &N);
		printf("Case #%d: ", t);
		char s[10001];
		scanf("%s", &s);
		for(int i=0; s[i]; i++){
			if(s[i]=='E') printf("S");
			else printf("E");
		}
		printf("\n");
	}
}
