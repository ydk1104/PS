#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	char s[202] = {0, };
	for(int i=0; i<N; i++){
		s[2*i] = ' ';
		s[2*i+1] = '*';
	}
	for(int i=1; i<=N; i++){
		printf("%s\n", s+(i%2));
	}
}
