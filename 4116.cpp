#include<stdio.h>
#include<string.h>
#include<vector>
#include<tuple>

using namespace std;
vector<pair<int, char> > v[10001];
char s[1001];
int slen;
int ans;

void dfs(int now, char x[], int xlen){
	if(xlen>=slen){
		if(!strcmp(s, x+(xlen-slen))) ans++;
	}
	for(auto i:v[now]){
		x[xlen++] = i.second;
		dfs(i.first, x, xlen);
		x[--xlen] = 0;
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int x, y;
		char c;
		scanf("%d %d %c", &x, &y, &c);
		v[x].push_back({y,c});
	}
	scanf("%s", &s);
	for(int i=0; s[i]; i++) slen++;
	char now[10001] = {0, };
	dfs(1, now, 0);
	printf("%d",ans);
}
