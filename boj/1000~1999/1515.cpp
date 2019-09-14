#include<stdio.h>

int find(int start, int now){
	int temp = start%now - start%(now/10);
	while(temp>=10) temp/=10;
//	printf("%d %d %d %d\n",start, now, start%now - start%(now/10), temp);
	return temp;
}

int main(void){
	char s[3001];
	scanf("%s", &s);
	int start = 1;
	int now = 10;
	for(int i=0; s[i]; i++){
		v:
		if(now==1){
			start++;
			while(now<=start) now*=10;
		}
		if(s[i]-'0' == find(start, now)){
			now/=10;
			continue;
		}
		now/=10;
		goto v;
	}
	printf("%d", start);
}
