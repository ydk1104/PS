#include<stdio.h>

int main(void){
	int x, y;
	char s[9] = {0,};
	char a[2][10] = {{"false"},{"true"}};
	int cnt=0;
	int ans=0;
	while(1){
		cnt++;
		scanf("%d %s %d", &x, &s, &y);
		if(*s=='E') break;
		if(*s=='>'){
			if(s[1]) ans=x>=y;
			else ans=x>y;
		}
		if(*s=='<'){
			if(s[1]) ans=x<=y;
			else ans=x<y;
		}
		if(*s=='=') ans=x==y;
		if(*s=='!') ans=x!=y;
		printf("Case %d: %s\n", cnt, a[ans]);
	}
}
