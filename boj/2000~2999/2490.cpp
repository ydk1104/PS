#include<stdio.h>

int main(void){
	for(int i=1; i<=3; i++){
		char ans = 'D';
		for(int j=1; j<=4; j++){
			int temp;
			scanf("%d", &temp);
			ans -= temp;
		}
		if(ans == '@'){
			ans += 5;
		}
		printf("%c\n", ans);
	}
}
