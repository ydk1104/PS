#include<stdio.h>

char s[400000];
char ans[1000001];

int main(void){
	scanf("%s", &s);
	for(int i=0; s[i]; i++){
		s[i]-='0';
		for(int j=2; j>=0; j--){
			ans[i*3+j] = s[i]%2+'0';
			s[i]/=2;
		}
	}
	int i=0;
	while(ans[i]=='0') i++;
	if(ans[i] == 0) i--;
	printf("%s", ans+i);
}
