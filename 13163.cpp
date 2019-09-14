#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		getchar();
		char s[101];
		scanf("%[^\n]s", &s);
		char *p = s;
		while(*p!=' ') p++;
		printf("god");
		for(; *p; p++){
			if(*p==' ') continue;
			printf("%c",*p);
		}
		printf("\n");
	}
}
