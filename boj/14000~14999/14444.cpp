#include<stdio.h>

char s[100010] = {-1, };
int dp[100010][27] = {0, };

int main(void){
	scanf("%s", (s+1));
	int ans=1;
	for(int i=1; i<=50000; i++) s[i] = 'a';
	for(int i=1; s[i]; i++){
		for(int j=1; j<=26; j++){
			dp[i][j] = dp[i-1][j];
		}
		
		int left=i-1, right=i+1, temp=1;
		while(s[left] == s[right]) left--, right++, temp+=2;
		ans = ans<temp ? temp : ans;
		if(s[i] != s[i+1]) continue;
		left=i-1, right=i+2, temp=2;
		while(s[left] == s[right]) left--, right++, temp+=2;
		ans = ans<temp ? temp : ans;
	}
	printf("%d", ans);
}
