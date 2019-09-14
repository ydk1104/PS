#include<stdio.h>

int main(void){
	int N, M;
	char s[52][52];
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%s",&s[i]);
	int ans=0;
	for(int i=0;i<N;i++){
		if(i>M) break;
		for(int j=i; j<N; j++){
			for(int k=i; k<M; k++){
				if((s[j][k] == s[j-i][k]) && (s[j-i][k] == s[j][k-i]) && (s[j][k-i] == s[j-i][k-i])) ans=i+1;
			}
		}
	}
	printf("%d",ans*ans);
}
