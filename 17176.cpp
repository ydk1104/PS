#include<stdio.h>

int main(void){
	int N,x;
	char code[53] = {' ', };
	for(int i=0; i<26; i++) code[i+1] = 'A'+i;
	for(int i=0; i<26; i++) code[i+27] = 'a'+i;
	int cnt[128] = {0, };
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &x), cnt[code[x]]++;
	getchar();
	int ans=0;
	for(int i=0; i<N; i++){
		char x=getchar();
		cnt[x]--;
		if(cnt[x]==-1) ans=1;
	}
	char a[] = {'y', 'n'};
	printf("%c",a[ans]);
}
