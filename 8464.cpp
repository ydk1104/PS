#include<stdio.h>

const int MAX = 450000;
using ll = long long;

ll m[MAX+1];

ll go(ll N){
	ll temp = 0;
	for(ll i=1; i*i<=N; i++) temp += m[i] * (N/(i*i));
	return N-temp;
}

int main(void){
	ll N;
	scanf("%lld", &N);
	for(int i=1; i<=MAX; i++) m[i] = 1;
	for(ll i=2; i<=MAX; i++){
		if(m[i] != 1) continue;
		for(int j=i; j<=MAX; j+=i) m[j] *= -2;
		for(ll j=i*i; j<=MAX; j+=i*i) m[j] = 0;
	}
	for(int i=2; i<=MAX; i++){
		if(m[i] > 0 ) m[i] = 1;
		if(m[i] < 0) m[i] = -1;
	}
	ll l=1, r=3e10;
	while(l<=r){
		ll mid = (l+r)/2;
		if(go(mid)==N && go(mid-1)<N){
			printf("%lld", mid);
			break;
		}
		else if(go(mid)>=N) r = mid;
		else l = mid;
	}
}
