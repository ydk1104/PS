#include<stdio.h>

int main(void){
	int c[2];
	int cnt = 0;
	scanf("%d", &c[cnt++]);
	while(getchar()==' '){
		scanf("%d", &c[cnt]);
		if(c[cnt]<c[1-cnt]){
			printf("Bad");
			return 0;
		}
		else{
			cnt=1-cnt;
		}
	}
	printf("Good");
}
