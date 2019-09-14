#include<stdio.h>

int main(void){
	char s[21];
	scanf("%s", &s);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i==1 && j==1) printf(":%s:", s);
			else printf(":fan:");
		}
		printf("\n");
	}
}
