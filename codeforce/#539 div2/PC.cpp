#include<stdio.h>
#define ll long long

ll a[300001];
ll check[300001];
ll cnt;

void Check(int left, int right){
	ll mid = (left+right)/2;
	printf("%d %d %d\n", left, right, mid);
	ll c1 = check[mid] ^ check[left-1];
	ll c2 = check[right] ^ check[mid];
	if(c1 == c2) cnt++;
	printf("c1 c2 : %d %d\n", c1, c2);
}

int main(void){
	ll N;
	scanf("%lld", &N);
	for(int i=0; i<N; i++) scanf("%lld", &a[i]);
//	for(int i=0; i<N; i++) a[i] = 0;
	for(int i=1; i<=N; i++){
		check[i] = check[i-1] ^ a[i-1];
//		printf("%lld\n", check[i]);
	}
	for(int k=1; k<N; k+=2){
		for(int left=1; left<=N-k; left++){
			Check(left, left+k);
		}
	}
	printf("%lld", cnt);
}
