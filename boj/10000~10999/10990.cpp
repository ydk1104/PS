#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	char s[220] = {0,};
	for(int i=0; i<2*N; i++) s[i]=' ';
	for(int i=0; i<N; i++){
		s[N-i] = '*';
		s[N+i] = '*';
		s[N+i+1] = 0;
		printf("%s", s+1);
		s[N-i] = ' ';
		s[N+i] = ' ';
		if(i!=N-1) printf("\n");
	}
}
