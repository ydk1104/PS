#include<stdio.h>
#define max(a,b) (a>b) ? (a) : (b)

int main(void){
	char c;
	int cnt[300] = {0, };
	int cntmax = 0;
	c = getchar();
	while(c!=EOF){
		if((c>='a' && (c<='z'))){
			cnt[c]++;
			cntmax = max(cntmax, cnt[c]);
		}
		c = getchar();
	}
	for(int i='a'; i<='z'; i++){
		if(cnt[i] == cntmax) printf("%c", i);
	}
}
