#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	char s[1001], ans=0;
	for(int i=0; i<N; i++){
		scanf("%s", &s);
		for(int i=1; s[i]; i++){
			if(s[i]=='D' && s[i-1]=='C'){
				goto v;
			}
		}
		ans++;
		v:;
	}
	printf("%d",ans);
}
