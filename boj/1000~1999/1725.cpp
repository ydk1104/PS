#include<stdio.h>
#include<stack>
#define max(a,b) ((a)>(b)?(a):(b))
#define ll long long int

using namespace std;

stack<pair<ll, ll> > s;

int main(void){
	int N;
	scanf("%d", &N);
	while(N!=0){
		ll ans=0;
		s.push(make_pair(-1, 0));
		for(int i=1; i<=N; i++){
			ll x;
			scanf("%lld", &x);
			if(x > s.top().first){
				s.push(make_pair(x, i));
				continue;
			}
			while(x <= s.top().first){
				pair<ll, ll> temp = s.top(); s.pop();
				ans = max(ans, temp.first * (i-1-s.top().second));
			}
			s.push(make_pair(x, i));
		}
		while(!s.empty()){
			pair<ll, ll> temp = s.top(); s.pop();
			if(s.empty()) break;
			ans = max(ans, temp.first * (N - s.top().second));
		}
		printf("%lld\n", ans);
		scanf("%d", &N);
	}
}
