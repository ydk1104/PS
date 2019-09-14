#include<stdio.h>

char s[30][30];
int N, M;
int ans;

void find(int x, int y, int cnt, int check[]){
	if(x<0 || y<0 || x>=N || y>=M) return;
	if(check[s[x][y]-'A']) return;
	check[s[x][y]-'A']++;
	cnt++;
	ans = (cnt > ans) ? cnt : ans;
	find(x+1, y, cnt, check);
	find(x-1, y, cnt, check);
	find(x, y+1, cnt, check);
	find(x, y-1, cnt, check);
	check[s[x][y]-'A']--;
	cnt--;
	return;
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%s", &s[i]);
	int check[26] = {0, };
	find(0, 0, 0, check);
	printf("%d", ans);
}
