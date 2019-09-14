#include<stdio.h>

char a[1000001];

int main(void){
	int cnt = 0;
	scanf("%[^\n]s", &a);
	if(a[0] != ' '){
		cnt++;
	}
	for(int i=1; a[i]!=0; i++){
		if(cnt==0) cnt++;
		if(a[i] == ' '){
			cnt++;
			if(a[i+1] == 0) cnt--;
		}
	}
	printf("%d", cnt);
}
