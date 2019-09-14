#include<stdio.h>

int main(void){
	char s[2][9];
	int a[16];
	gets(s[0]);
	gets(s[1]);
	for(int i=0; i<8; i++)
		a[2*i] = s[0][i]-'0', a[2*i+1] = s[1][i]-'0';
	for(int i=15; i>1; i--)
		for(int j=0; j<i; j++)
			a[j] += a[j+1];
	a[0]+=10;
	printf("%d%d", a[0]%10, a[1]%10);
}
