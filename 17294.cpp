#include<stdio.h>

int main(void){
	char s[65];
	scanf("%s", &s);
	for(int i=2; s[i]; i++){
		if(s[i]-s[i-1] != s[i-1]-s[i-2]){
			printf("��ĩ��!! <(�� ? ��)>");
			return 0;
		}
	}
	printf("?(?????)?..�Ƣ� ����!!");
}
