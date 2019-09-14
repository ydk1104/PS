#include<stdio.h>

void count(char x, int cnt[]){
	if(x==' '){
		cnt[4]++;
	}
	else if(x>='0'){
		if(x>='A'){
			if(x>='a') cnt[1]++;
			else cnt[2]++;
		}
		else cnt[3]++;
	}
}

int main(void){
	int cnt[5] = {0, };
	char c = getchar();
	while(c!=EOF){
		for(int i=1; i<=4; i++){
			cnt[i] = 0;
		}
		count(c, cnt);
		while(c!='\n'){
			c = getchar();
			count(c, cnt);
		}
		for(int i=1; i<=4; i++){
			printf("%d", cnt[i]);
			if(i!=4) printf(" ");
			else printf("\n");
		}
		c = getchar();
	}
}
