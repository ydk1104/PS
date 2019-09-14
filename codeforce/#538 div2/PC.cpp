#include<stdio.h>
#define MAX 2000000
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long int

ll N, B;

ll count[MAX+1];
ll countB[MAX+1];
ll prime[MAX+1];
ll cnt;

void found(ll x){
	for(ll i=2; i*i<=x; i++){
		if(x%i) continue;
		prime[cnt++] = i;
		while(x%i==0){
			countB[i]++;
			x/=i;
		}
	}
	if(x==1) return;
	prime[cnt++] = x;
	if(x<=MAX) countB[x]++;
}

ll update(ll N, ll x){
	ll temp = N, cnt = 0;
	while(temp>1){
		cnt += temp/x;
		temp /= x;
	}
	if(x<=MAX) count[x] = cnt;
	return cnt;
}

int main(void){
	scanf("%lld %lld", &N, &B);
	found(B);
	ll ans = -1;
	if(prime[cnt-1] >= MAX){
		ans = update(N, prime[cnt-1]);
		cnt--;
	}
	for(int i=0; i<cnt; i++){
		int now = prime[i];
		update(N, now);
		if(ans == -1) ans = count[now] / countB[now];
		ans = min(ans, count[now] / countB[now]);
	}
	printf("%lld", ans);
}
