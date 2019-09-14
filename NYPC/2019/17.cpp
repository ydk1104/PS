#include<stdio.h>

int main(void){
	char s[2000001] = {0, };
	int ans=0;
	scanf("%s", s);
	int len=0;
	for(int i=0; s[i]; i++, len++);
	for(int i=0; i<len; i++){
		int left=i, right=i+len-1;
		while(left <= right && s[left] == s[right]) left++, right--;
		if(left>right) ans++, printf("%s\n", s+i);
		s[i+len] = s[i];
	}
	printf("%d", ans);
}
