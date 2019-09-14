#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s[20001][51];

int compare(const void *a, const void *b){
	char *a1 = *(char**)a;
	char *b1 = *(char**)b;
	int alen = strlen(a1);
	int blen = strlen(b1);
	if(alen == blen){
		return strcmp(a1, b1);
	}
	else{
		if(alen>blen){
			return 1;
		}
		return -1;
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", &s[i]);
	}
	char* p[20001];
	for(int i=0; i<N; i++){
		p[i] = s[i];
	}
	qsort(p, N, sizeof(char*), compare);
	for(int i=0; i<N; i++){
		if(*p[i] != '\0'){
			printf("%s\n", p[i]);		
			for(int j=1; (i+j<N)&&(strcmp(p[i], p[i+j]) == 0); j++){
				*p[i+j] = '\0';
			}
		}
	}
}
