#include<stdio.h>

int main(void){
	int N;
	char s[65005];
	scanf("%d", &N);
	scanf("%s", &s);
	int ans=0;
	for(int i=0; s[i]; i++){
		if(s[i]%2==0) ans+=i+1;
	}
	printf("%d\n", ans);
}
