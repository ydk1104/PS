#include<stdio.h>
#include<stdlib.h>

char s[27];
int order[26];
char ans[21][31];
int cnt;

int compare(const void *pa, const void *pb){
	char* a = (char*) pa;
	char* b = (char*) pb;
	while(*a != 0 && *b != 0){
		if(*a != *b){
			return order[*a-'A'] - order[*b-'A'];
		}
		a++;
		b++;
	}
	if(*a == 0) return -1;
	return 1;
}

int main(void){
	int N;
	scanf("%d", &N);
	while(N){
		cnt++;
		scanf("%s", &s);
		for(int i=0; i<26; i++){
			order[s[i]-'A'] = i;
		}
		for(int i=0; i<N; i++){
			scanf("%s", &ans[i]);
		}
		qsort(ans, N, sizeof(char)*31, compare);
		printf("year %d\n", cnt);
		for(int i=0; i<N; i++){
			printf("%s\n", ans[i]);
		}
		scanf("%d", &N);
	}
}
