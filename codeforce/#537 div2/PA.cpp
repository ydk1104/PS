#include<stdio.h>

char s[2][1000001];
int i, flag;

int check(int x, int y){
	if(s[x][y] == 'a' || s[x][y] == 'e' || s[x][y] == 'i' || s[x][y] == 'o' || s[x][y] == 'u') return 1;
	if(s[x][y] == 0) return -1;
	return 0;
}

int main(void){
	scanf("%s\n%s", &s[0], &s[1]);
	flag = 1;
	for(i=0; s[0][i]!=0; i++){
		if(check(0, i) != check(1, i)) flag = 0;
	}
	if(s[1][i]!=0) flag=0;
	if(flag) printf("YES");
	else printf("NO");
}
