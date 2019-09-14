#include<stdio.h>

void sort(char *a, char *b){
	if(*a < *b){
		char temp = *a;
		*a = *b;
		*b = temp;
	}
}

int main(void){
	char N[20];
	scanf("%s", &N);
	for(int i=0; N[i]!='\0'; i++){
		for(int j=i+1; N[j]!='\0'; j++){
			sort(&N[i], &N[j]);
		}
		printf("%c", N[i]);
	}
}
