#include<stdio.h>

class node{
	public:
	char s;
	int num;
};

char s[100010];
node S[100010];

int main(void){
	int ans = 0;
	scanf("%s", &s);
	for(int i=0; s[i]!=0; i++){
		S[i].s = s[i];
		S[i].num = i-1;
	}
	for(int i=1; S[i].s != 0; i++){
		if(S[i].s == S[S[i].num].s){
			ans++;
			S[i+1].num = S[S[i].num].num;
		}
	}
	if(ans%2) printf("Yes");
	else printf("No");
}
