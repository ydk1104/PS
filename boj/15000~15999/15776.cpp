#include<stdio.h>

char s[1000002];

int main(void){
	int ans = 0;
	int cnt = 0;
	scanf("%d", &s);
	for(int i=0; s[i]!='\0'; i++){
		if(s[i] == 0){
			cnt++;
		}
		else{
			ans += cnt;
			cnt = 0;
		}
	}
	printf("%d", ans);
}
