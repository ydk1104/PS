#include<stdio.h>

char s[3][303];

int main(void){
	for(int i=0; i<3; i++){
		scanf("%s", s[i]);
	}
	int left = 0;
	int right = 0;
	int pr = 0;
	while((s[0][left] != 0) && (s[1][right] != 0)){
		if(s[0][left] == s[2][pr]){
			printf("1");
			left++;
		}
		else{
			printf("2");
			right++;
		}
		pr++;
	}
	if(s[0][left] != 0){
		for(; s[0][left]!=0; left++){
			printf("1");
		}
	}
	else{
		for(; s[1][right]!=0; right++){
			printf("2");
		}
	}
}
