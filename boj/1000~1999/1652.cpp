#include<stdio.h>

char s[101][101];
int ans[2];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%s", &s[i]);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(s[i][j] == '.' && s[i][j+1] == '.'){
				ans[0]++;
				while(s[i][j]=='.') j++;
			}
		}
		for(int j=0; j<N; j++){
			if(s[j][i] == '.' && s[j+1][i] == '.'){
				ans[1]++;
				while(s[j][i]=='.') j++;
			}
		}
	}
	printf("%d %d", ans[0], ans[1]);
}
