#include<stdio.h>

char s[1000001];
int a[52];
int cnt = 0;

int max(int x, int y){
	if(a[x]>a[y]){
		return x;
	}
	if(a[x]==a[y]){
		cnt++;
		return x;
	}
	else{
		cnt = 0;
		return y;
	}
}

int main(void){
	scanf("%s", &s);
	for(int i=0; s[i]!='\0'; i++){
		int temp = s[i];
		if(temp>=97){
			temp -= 97;
		}
		else{
			temp -= 65;
		}
		a[temp]++;
	}
	int ans = 0;
	for(int i=1; i<=25; i++){
		ans = max(ans, i);
	}
	if(cnt==0){
		printf("%c", ans+65);
	}
	else{
		printf("?");
	}
}
