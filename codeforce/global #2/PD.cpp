#include<stdio.h>
#include<set>
#define ll long long
#include<algorithm>
#include<vector>

using namespace std;

struct sc{
	ll x;
	ll sum;
	ll cnt;
};

ll a[100001];
set<ll> s;
vector<ll> v;
ll ans[100001];
sc tosum[100001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%lld", &a[i]);
		s.insert(a[i]);
	}
	ll prev = -1;
	for(auto p=s.begin(); p!=s.end(); p++){
		if(prev != -1){
			v.push_back(*p - prev);
		}
		prev = *p;
	}
	ll cnt=s.size(), sum=cnt;
	prev=0;
	tosum[0].x = prev;
	tosum[0].cnt = cnt;
	tosum[0].sum = sum;
	sort(v.begin(), v.end());
	int i=1;
	for(auto p=v.begin(); p!=v.end(); i++, p++){
		while(*p == *(p+1)) p++, i++, cnt--;
		sum += (*p-prev)*cnt-1;
		cnt--;
		tosum[i].cnt = cnt;
		tosum[i].sum = sum;
		tosum[i].x = *p;
		prev = *p;
	}
	tosum[i].cnt = cnt;
	tosum[i].sum = sum;
	tosum[i].x = prev;
	int Q;
	scanf("%d", &Q);
	while(Q--){
		ll x, y;
		scanf("%lld %lld", &x, &y);
		ll d = y-x;
		ll now = lower_bound(v.begin(), v.end(), d) - v.begin();
		while(*(v.begin()+now) == d) now++;
//		if(v.begin() + now == v.end()) now--;
//		printf("test : %d %d %d %d\n", now, tosum[now].x, tosum[now].cnt, tosum[now].sum);
		ll sum = tosum[now].sum + tosum[now].cnt * (d-tosum[now].x);
		printf("%lld ", sum);
	}
}
