#include<stdio.h>
#include<string.h>

char s[1000001];
char WH[3][1001];

int main(void){
	scanf("%[^0]s", &s);
	getchar();
	for(int i=0; i<3; i++){
		scanf("%s\n", WH[i]); // WHO, WHERE, WHAT
	}
	for(int i=2; i>0; i--){
		for(int j=0; WH[i][j] != 0; j++){
			strncmp(WH[i][j], "WHO", 3);
		}
	}
	
}
