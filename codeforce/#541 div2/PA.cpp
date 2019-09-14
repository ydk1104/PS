#include<stdio.h>
#include<algorithm>
#define ll long long int

using namespace std;

//ll a[300001];
ll a, b, c, d;

int main(void){
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	ll ans = 0;
	ans += 2*a+2*b+4;
	ans += 2*c+2*d+4;
	ans -= c+2;
	ans -= c+2;
//	for(int i=0; <N; i++) scanf("%lld", &a[i]);
	printf("%lld", ans);
}
