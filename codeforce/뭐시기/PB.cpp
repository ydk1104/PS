#include<stdio.h>

char s[100001];
char s2[100001];
int cnt;
int len;

int main(void){
	scanf("%s", &s);
	for(int i=0; s[i]; i++, len++){
		if(s[i]!='a') s2[cnt++] = s[i];
	}
	if(cnt%2){
		printf(":(");
		return 0;
	}
	cnt/=2;
	for(int i=len-cnt, j=0; i<len; i++, j++){
		if(s[i] != s2[j]){
			printf(":(");
			return 0;
		}
	}
	s[len-cnt]=0;
	printf("%s", s);
}
