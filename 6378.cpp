#include<stdio.h>

int dirt(char N[]){
	int n = 0;
	for(int i=0; N[i]!='\0'; i++){
		n += N[i]-48;
	}
	while(n>9){
		int temp = 0;
		while(n>0){
			temp += n%10;
			n /= 10;
		}
		n = temp;
	}
	return n;
}

int main(void){
	char N[1001];
	int sum = 0;
	scanf("%s", &N);
	while(N[0] != '0' || N[1] != '\0'){
		printf("%d\n", dirt(N));
		scanf("%s", &N);
	}
}
