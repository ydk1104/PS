#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for(; T>0; T--){
		int N;
		scanf("%d", &N);
		char s[30];
		scanf("%s", &s);
		for(int i=0; s[i]!=0; i++){
			for(int j=0; j<N; j++){
				printf("%c", s[i]);
			}
		}
		printf("\n");
	}
}
