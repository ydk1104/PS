#include<stdio.h>
#include<vector>
#include<algorithm>

int N;

int main(void){
	scanf("%d", &N);
	while(N--){
		char s[101];
		scanf("%s", &s);
		int even = 0, zero = 0, sum = 0;
		for(int i=0; s[i]; i++){
			sum += s[i]-'0';
			if(zero==0 && s[i]=='0') zero=1;
			else if(s[i]%2==0) even=1;
		}
		printf("%s\n", (sum%3 || !zero || !even )? "cyan" : "red");
	}
}
