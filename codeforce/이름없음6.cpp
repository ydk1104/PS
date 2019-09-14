#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		char s[301];
		scanf("%d\n%s", &x, &s);
		if(s[0] >= s[1] && x == 2) printf("NO\n");
		else printf("YES\n2\n%c %s\n", s[0], s+1);
	}
}
