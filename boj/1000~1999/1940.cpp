#include<stdio.h>
#define min(a,b) ((a)>(b) ? (b) : (a))

int check[10000001];
int ans;

int main(void){
	int N, M;
	scanf("%d\n%d", &N, &M);
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d", &x);
		check[x]++;
	}
	for(int i=0; i<=M/2-1; i++){
		ans += min(check[i], check[M-i]);
		check[i] = 0;
	}
	if(M%2) ans+=min(check[M/2], check[M-M/2]);
	else ans+=check[M/2]/2;
	printf("%d", ans);
}
