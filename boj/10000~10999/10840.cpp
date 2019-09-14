#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

char s[2][1501];

int f(char s[], int check[], int gap){
	int cnt=0;
	int temp[26];
	for(int i=0; i<26; i++){
		if(check[i]) cnt++;
		temp[i] = check[i];
	}
	int left=0, right=0;
	while(right<gap){
		int now=s[right]-'a';
		temp[now]--;
		if(!temp[now]) cnt--;
		right++;
	}
	do{
	for(int i=0; i<26; i++) printf("%d ", temp[i]);
	printf("%d\n", cnt);
		if(!cnt) return 1;
		int now=s[left]-'a';
		if(!temp[now]) cnt++;
		temp[now]++;
//		printf("%d ", now);
		left++;
		now = s[right]-'a';
//		if(now<0) return 0;
		temp[now]--;
//		printf("%d\n", now);
		right++;
		if(!temp[now]) cnt--;
	}while(s[right]);
	return 0;
}

int main(void){
	scanf("%s\n%s", &s[0], &s[1]);
	int left=0, right=0, check[27] = {0,}, ans=0;
	while(s[0][right]){
		if(f(s[1], check, right-left)){
			printf("%d %d %d\n", left, right);
			ans = max(ans, right-left);
			check[s[0][right]-'a']++;
			right++;
		}
		else check[s[0][left]-'a']--, left++;
	}
	if(f(s[1], check, right-left)) ans = max(ans, right-left);
	printf("%d", ans);
}
