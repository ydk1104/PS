#include<stdio.h>

int main(void){
	char s[100001];
	int ans = 0;
	int cnt = 0;
	scanf("%s", &s);
	for(int i=0; s[i]!='\0'; i++){
		if(s[i] == '('){
			if(s[i+1] == ')'){
				ans += cnt;
				s[i+1] = 'a';
			}
			else{
				cnt++;
				ans++;
			}
		}
		else if(s[i]==')'){
			cnt--;
		}
	}
	printf("%d", ans);
}
