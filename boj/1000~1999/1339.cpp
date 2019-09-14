#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s[10][10];
int num[26];

int compare(const void *pa, const void *pb){
	int* a = (int*) pa;
	int* b = (int*) pb;
	if(*a>*b) return -1;
	return 1;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", &s[i]);
		int cnt = 1;
		for(int j=strlen(s[i])-1; j>=0; j-- ){
			num[s[i][j]-'A'] += cnt;
			cnt *= 10;
		}
	}
	qsort(num, 26, sizeof(int), compare);
	int ans = 0;
	for(int i=0; i<10; i++){
		ans += (9-i) * num[i];
	}
	printf("%d", ans);
}
