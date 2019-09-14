#include<stdio.h>
#define max(a,b) ((a)>(b) ? (a) : (b))

int main(void){
	char s[5001];
	int row = 0, ans = 0;
	scanf("%s", &s);
	for(int i=0; s[i]!=0; i++){
		if(s[i] == '1') row++;
		else{
			ans = max(row, ans);
			row = 0;
		}
	}
	printf("%d", max(ans, row));
}
