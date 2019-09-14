#include<stdio.h>

int main(void){
	int N;
	char s[200005];
	scanf("%d\n%s", &N, &s);
	int ans = 0;
	for(int i=0; i<N; i++){
		if(s[i] == s[i+1]){
			ans++;
			i++;
			if(s[i-1] != 'R' && s[i+1] != 'R') s[i] = 'R';
			if(s[i-1] != 'G' && s[i+1] != 'G') s[i] = 'G';
			if(s[i-1] != 'B' && s[i+1] != 'B') s[i] = 'B';
		}
	}
	printf("%d\n%s", ans, s);
}
