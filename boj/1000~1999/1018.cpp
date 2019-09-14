#include<stdio.h>

int abs(int x){return x>0?x:-x;}

char s[51][51];

int main(void){
	int N, M, ans=64;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%s", &s[i]);
	for(int i=0; i<=N-8; i++){
		for(int j=0; j<=M-8; j++){
			int cnt=0;
			int bw[2][2] = {0,};
			for(int k=0; k<8; k++){
				for(int l=0; l<8; l++){
					if(s[i+k][j+l]=='W')  bw[(k+l)%2][0]++;
					else bw[(k+l)%2][1]++;
				}
			}
//			printf("%d %d %d %d\n", bw[0][0], bw[0][1], bw[1][0], bw[1][1]);
			int a1 = abs(32-bw[0][0]) + abs(32-bw[1][1]);
			int a2 = abs(32-bw[0][1]) + abs(32-bw[1][0]);
			a1=a1>a2?a2:a1;
			ans=ans>a1?a1:ans;
		}
	}
	printf("%d",ans);
}
