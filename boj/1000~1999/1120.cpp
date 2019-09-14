#include<stdio.h>

int strcmp(char *a, char *b){
	int cnt=0;
	for(int i=0; a[i]; i++){
		if(!b[i]) return 100;
		if(a[i]!=b[i]) cnt++;
	}
	return cnt;
}

int main(void){
	char a[51], b[51];
	scanf("%s %s", &a, &b);
	int min=100;
	for(int i=0; b[i]; i++){
		int now = strcmp(a, b+i);
		min = min>now ? now : min;
	}
	printf("%d",min);
}
