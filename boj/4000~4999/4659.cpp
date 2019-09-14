#include<stdio.h>
#include<string.h>

int check(char s[]){
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	for(int i=0; s[i]!='\0'; i++){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
			cnt1++;
			cnt3 = 0;
			cnt2++;
			if(cnt2 == 3){
				return 0;
			}
		}
		else{
			cnt2 = 0;
			cnt3++;
			if(cnt3 == 3){
				return 0;
			}
		}
		if(i>0 && s[i] == s[i-1]){
			if(s[i]=='e' || s[i]=='o'){
				
			}
			else{
				return 0;
			}
		}
	}
	if(cnt1 == 0){
		return 0;
	}
	return 1;
}

int main(void){
	char s[21];
	scanf("%s", &s);
	while((strcmp(s, "end")!= 0)){
		if(check(s)){
			printf("<%s> is acceptable.\n", s);
		}
		else{
			printf("<%s> is not acceptable.\n", s);
		}
		scanf("%s", &s);
	}
}
