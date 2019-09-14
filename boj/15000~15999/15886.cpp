#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	char s[1001];
	scanf("%s", &s);
	int ans = 0;
	for(int i=0; s[i+1]!=0; i++){
		if((s[i]=='E') && s[i+1]=='W') ans++;
	}
	printf("%d", ans);
}
