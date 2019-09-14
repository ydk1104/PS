#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	char s[51];
	for(int i=1; i<=N; i++){
		scanf("%s", &s);
		for(int j=0; s[j]!='\0'; j++){
			if(s[j] == 'Z'){
				s[j] = 'A';
			}
			else{
				s[j]++;
			}
		}
		printf("String #%d\n%s\n\n", i, s);
	}
}
