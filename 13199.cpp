#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for(; T>0; T--){
		int P, M, F, C;
		scanf("%d %d %d %d", &P, &M, &F, &C);
		int cou = M/P*C;
		int ans = (cou-F)/(F-C)+1 - (cou/F);
		if(P>M || F>cou) ans=0;
		printf("%d\n", ans);
	}
}
