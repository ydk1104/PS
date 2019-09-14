#include<stdio.h>

int main(void){
	int N, M;
	char s[12][12];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%s", &s[i]);
	}
	for(int i=0; i<N; i++){
		for(int j=M-1; j>=0; j--){
			printf("%c", s[i][j]);
		}
		printf("\n");
	}
}
