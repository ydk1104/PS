#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		char s[30];
		scanf("%s", &s);
		char ans[2][30] = {0, };
		int j = 0;
		int k = 0;
		int check = 0;
		while(check<2){
			ans[(j+k)%2][(j+k)/2] = s[j];
			j++;
			if(s[j] == '\0'){
				if(j%2 == 0) check++;
				k = j;
				j = 0;
				check++;
			}			
		}
		printf("%s\n%s\n", ans[0], ans[1]);
	}
}
