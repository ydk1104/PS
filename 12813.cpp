#include<stdio.h>
#include<string.h>
#define MAX 100000

int main(void){
	char a[100001];
	char b[100001];
	scanf("%s\n%s", &a, &b);
	for(int i=0; i<MAX; i++){
		printf("%d", (a[i]-'0')&&(b[i]-'0'));
	}
	printf("\n");
	for(int i=0; i<MAX; i++){
		printf("%d", (a[i]-'0')||(b[i]-'0'));
	}
	printf("\n");
	for(int i=0; i<MAX; i++){
		printf("%d", (a[i]-'0')^(b[i]-'0'));
	}
	printf("\n");
	for(int i=0; i<MAX; i++){
		printf("%d", 1-(a[i]-'0'));
	}	
	printf("\n");
	for(int i=0; i<MAX; i++){
		printf("%d", 1-(b[i]-'0'));
	}	
}
