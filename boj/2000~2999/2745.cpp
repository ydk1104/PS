#include<stdio.h>

char s[50];
int N;

int f(char x){
	if(x<='9') return x-'0';
	return x-'A'+10;
}

int main(void){
	scanf("%s %d", &s, &N);
	int i=0;
	while(s[i]) i++;
	int ans=0;
	i--;
	for(int j=1; i>=0; i--, j*=N){
		ans+=f(s[i])*j;	
	}
	printf("%d", ans);
}
