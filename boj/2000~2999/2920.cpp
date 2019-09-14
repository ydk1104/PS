#include<stdio.h>
#include<string.h>

int main(void){
	char a[10] = {0, };
	for(int i=0; i<8; i++){
		scanf("%c", &a[i]);
		getchar();
	}
	a[8] = '\0';
	if(strcmp(a, "12345678") == 0){
		printf("ascending");
	}
	else if(strcmp(a, "87654321") == 0){
		printf("descending");
	}
	else{
		printf("mixed");
	}
	return 0;
}
