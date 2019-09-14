#include<stdio.h>

int main(void){
	char s[21];
	scanf("%s", s);
	int ans=0;
	for(int i=0; s[i]; i++){
		if(s[i]>96) s[i]-=32;
		ans += s[i]-64;
	}
	bool check=false;
	for(int i=2; i*i<=ans; i++){
		if(ans%i==0) check=true;
	}
	printf("It is%sa prime word.", check?" not ":" ");
}
