#include<stdio.h>
 
int main(void){
	int N;
	char s[200001];
	int sum[2]={0,}, qu[2]={0,};
	scanf("%d", &N);
	scanf("%s", s);
	for(int i=0; s[i]; i++){
		if(s[i]=='?'){ qu[i/(N/2)]++;
	}
	else sum[i/(N/2)]+=s[i]-'0';
	}
	for(int i=0; i<=1; i++){sum[i]+=qu[i]/2*9;}
	char ans[2][20]={"Monocarp","Bicarp" };
	printf("%s", ans[sum[0]==sum[1]]);
}
