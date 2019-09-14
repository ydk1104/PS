#include<stdio.h>
using ll=long long;
ll map[1001][1001];
int fi[41] = {0, 1, };

ll fibo(ll x){
	if(x<0) return -x;
	return fi[x];
}

ll f(int k, int n){
	return fibo(n-k+1);
}

int main(void){
	int n, p;
	for(int i=2; i<=40; i++) fi[i] = fi[i-1] + fi[i-2];
	scanf("%d %d", &n, &p);
	for(int i=0; i<p; i++){
		for(int j=0; j<p; j++){
			scanf("%lld", &map[i][j]);
		}
	}
	int ans=0;
	for(int x=1; x<=n-p+1; x++){
		for(int y=1; y<=n-p+1; y++){
//			printf("/%d/ ", f(x, y));
			for(int i=0; i<p; i++){
				for(int j=0; j<p; j++){
//					printf("%d ", f(x+i, y+j));
					if(f(x+i, y+j) != map[i][j]) goto v;
				}
			}
			ans++;
			v:;
		}
//		printf("\n");
	}
	printf("%d",ans);
}
