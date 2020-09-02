#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>

char s[500500];
char p[101][10010];
bool check[2][101][500500];

void KMP(char* s, char* p, int now){
	int fail[10010] = {0, };
	for(int i=1, j=0; p[i-1]; i++){
		while(j && p[i] != p[j]) j = fail[j-1];
		if(p[i] == p[j]) fail[i] = ++j;
	}
	for(int i=0, j=0; s[i]; i++){
		while(j && s[i] != p[j]) j = fail[j-1];
		if(s[i] == p[j]) j++;
		if(!p[j]){
			check[0][now][i-j+1] = true;
			check[1][now][i] = true;
			j = fail[j-1];
		}
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%*d %s", &p[i]);
	}
	scanf("%*d %s", s);
	for(int i=0; i<N; i++){
		KMP(s, p[i], i);
	}
	int c[101] = {0, }, temp=0;
	int left = 0, right = 0;
	int ans = 1e9;
	for(int left=0, right=0; s[right]; right++){
		for(int i=0; i<N; i++){
			if(check[1][i][right])
				if(c[i]++ == 0)
					temp++;
		}
		while(temp==N){
			ans = std::min(ans, right-left+1);
			for(int i=0; i<N; i++){
				if(check[0][i][left])
					if(c[i]-- == 1)
						temp--;
			}
			left++;
		}
	}
	printf("%d", ans);
}
