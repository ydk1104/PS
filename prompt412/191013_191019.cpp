#include<stdio.h>

char s[100001];

int main(void){
	char mirror[] = "AHIMOTUVWXY";
	scanf("%s", &s);
	int len=0; while(s[len]) len++;
	for(int i=0; s[i]; i++){
		if(s[i] != s[len-i-1]) goto w;
		for(int j=0; mirror[j]; j++){
			if(s[i] == mirror[j]) goto v;
		}
		w:;
		printf("NO");
		return 0;
		v:;
	}
	printf("YES");
}
