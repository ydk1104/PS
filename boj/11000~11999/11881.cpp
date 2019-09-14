#include<stdio.h>
#include<algorithm>
#define MOD 1000000007
#define mod(x) ((x)%=MOD)
using ll=long long;

ll a[100001];
ll sum, vsum, psum;

bool cmp(ll a, ll b){
	return a>b;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%lld", &a[i]);
	std::sort(a, a+N, cmp);
	for(int i=0; i<N;){
		int j=i;
		while(a[i]==a[j]) j++;
		int cnt=j-i;
		ll nowsum = (((psum*a[i])%MOD)*cnt)%MOD;
		if(i>1) vsum += nowsum;
		mod(vsum);
		psum += ((sum*a[i])%MOD)*cnt;
		mod(psum);
		sum += a[i]*cnt;
		mod(sum);
		i=j;
	}
	printf("%d", vsum);
}
