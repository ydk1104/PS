#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	char s[101];
	scanf("%s", &s);
	for(int i=1; i<=N; i++){
		if(N%i) continue;
		char temp[101];
		for(int j=0; j<i; j++) temp[j] = s[i-j-1];
		for(int j=0; j<i; j++) s[j] = temp[j];
	}
	printf("%s", s);
}
