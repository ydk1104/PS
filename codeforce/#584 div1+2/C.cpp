#include<stdio.h>

char s[200001];
char ans[200001];

int main(void){
	int T;
	for(scanf("%d", &T); T--;){
		int N;
		scanf("%d", &N);
		scanf("%s", s);
		for(int p=0; p<10; p++){
			for(int i=0; s[i]; i++){
				if(s[i]-'0' < p){
					ans[i] = '1';
				}
				else if(s[i]-'0' > p){
					ans[i] = '2';
				}
				else{
					ans[i] = '3';
				}
			}
			int check=0;
			for(int i=N-1; i>=0; i--){
				if(ans[i]=='1') check=1;
				if(ans[i]=='3'){
					ans[i] = '1' + check;
				}
			}
			int prev[2] = {0, };
			for(int i=0; s[i]; i++){
				if(prev[ans[i]-'1'] > s[i]){
					goto v;
				}
				prev[ans[i]-'1'] = s[i];
			}
			ans[N] = 0;
			printf("%s\n", ans);
			goto w;
			v:;
		}
		printf("-\n");
		w:;
	}
}
