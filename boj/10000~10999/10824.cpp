#include<stdio.h>
#include<string.h>

int main(void){
	char s[4][10];
	int slen[4];
	for(int i=0; i<4; i++){
		scanf("%s", &s[i]);
		slen[i] = strlen(s[i]);
	}
	char merge[2][20] = {0, };
	for(int i=3; i>=0; i--){
		int k;
		if(i%2==1) k=0;
		else k=slen[i+1];
		for(int j=0; j<slen[i]; j++){
			merge[i/2][20-slen[i]-k+j] = s[i][j];
		}
	}
	char ans[40] = {0, };
	for(int i=0; i<=1; i++){
		for(int j=19; merge[i][j]!=0; j--){
			ans[19-j] += merge[i][j];
		}
	}
	int i;
	for(i=0; ans[i]!=0; i++){
		if(ans[i]>'0')ans[i] -= '0';
		if(ans[i]<'0')ans[i] += '0';
		if(ans[i]>'9'){
			ans[i]-=10;
			ans[i+1]+=1;
		}
	}
	for(i--; i>=0; i--){
		printf("%c", ans[i]);
	}
}
