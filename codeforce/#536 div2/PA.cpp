#include<stdio.h>

char s[501][501];
int ans;

int check(int x, int y){
	if(s[x][y] != 'X') return 0;
	if(s[x-1][y-1] != 'X') return 0;
	if(s[x-1][y+1] != 'X') return 0;
	if(s[x+1][y-1] != 'X') return 0;
	if(s[x+1][y+1] != 'X') return 0;
	return 1;
}

int main(void){
	int N; scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%s", &s[i]);
	for(int i=1; i<N-1; i++){
		for(int j=1; j<N-1; j++){
			if(check(i, j)) ans++;
		}
	}
	printf("%d", ans);
}
