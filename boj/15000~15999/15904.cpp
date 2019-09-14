#include<stdio.h>

int main(void){
	char check[5] = "UCPC";
	int pr = 0;
	char s[1001];
	scanf("%[^\n]s", &s);
	for(int i=0; s[i]!=0; i++){
		if(check[pr] == s[i]) pr++;
		if(pr==4) break;
	}
	if(pr==4) printf("I love UCPC");
	else printf("I hate UCPC");
}
