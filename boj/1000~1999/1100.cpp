#include<stdio.h>

int main(void){
	int ans = 0;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			char temp;
			scanf("%c", &temp);
			if((i+j)%2 == 0 && temp == 'F') ans++;
		}
		getchar();
	}
	printf("%d", ans);
}
