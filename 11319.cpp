#include<stdio.h>

char V[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
int check(char x){
	for(int i=0; i<10; i++){
		if(x==V[i]) return 1;
	}
	return 0;
}

int main(void){
	int N;
	scanf("%d\n", &N);
	char s[1001];
	for(;N--;){
		gets(s);
		int c=0,v=0;
		for(int i=0; s[i]; i++){
			if(s[i]==' ') continue;
			if(check(s[i])) v++;
			else c++;
		}
		printf("%d %d\n",c,v);
	}
}
