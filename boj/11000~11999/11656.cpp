#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char sa[1001][1001];

int compare(const void *a, const void *b){
	char *pa = (char*)a;
	char *pb = (char*)b;
	return strcmp(pa, pb);
}

int main(void){
	char s[1001];
	scanf("%s", &s);
	int len = strlen(s);
	for(int i=0; s[i]!=0; i++){
		strcpy(sa[i],&s[i]);
	}
	qsort(sa, 1001, sizeof(char)*1001, compare);
	for(int i=1000-len+1; i<=1000; i++){
		printf("%s\n", sa[i]);
	}
}
