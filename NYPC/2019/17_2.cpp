#include<stdio.h>

int main(void){
	char s[1000001];
	int cnt[26] = {0,}, odd=0, even=0;
	scanf("%s", &s);
	int len=0;
	for(; s[len]; len++) cnt[s[len]-'a']++;
	for(int i=0; i<26; i++){
		if(cnt[i]%2) odd++;
		else if(cnt[i]) even++;
	}
	if(odd + even == 1) printf("%d", len);
	else {
		if(odd>=2) printf("0");
		else{
			int ans=0;
			for(int i=0; i<len; i++){
				int left=i, right=i+len-1;
				while(left <= right && s[left] == s[right]) left++, right--;
				if(left>right) ans++, printf("%s\n", s+i);
				s[i+len] = s[i];
			}
			printf("%d", ans);
		}
	}
}
