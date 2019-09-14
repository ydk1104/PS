#include<stdio.h>

char s[101];

int main(void){
	scanf("%s", &s);
	int left=0, right=0;
	while(s[right]) right++;
	right--;
	while(left<=right){
		if(s[left]!=s[right]) goto v;
		left++;
		right--;
	}
	printf("1");
	return 0;
	v:
		printf("0");
}
