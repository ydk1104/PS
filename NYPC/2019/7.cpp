#include<stdio.h>

int B[11], ans;

int main(void){
	int N, M, S;
	scanf("%d %d %d", &N, &M, &S);
	while(M--){
		int x, type;
		scanf("%d %d", &x, &type);
		if(type){
			if(B[S]) B[S]--;
			else ans++;
			B[S=x]++;
		}
		else S=x;
	}
	printf("%d",ans);
}
