#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		char a[81];
		scanf("%s", &a);
		int score = 0;
		int cnt = 0;
		for(int i=0; a[i]!='\0'; i++){
			if(a[i] == 'O'){
				cnt ++;
				score += cnt;
			}
			else{
				cnt = 0;
			}
		}
		printf("%d\n", score);
	}
}
