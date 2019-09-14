#include<stdio.h>
#define ll long long
#include<set>
#include<algorithm>

using namespace std;

ll a[1001];

int main(void){
	ll N, H;
	scanf("%lld %lld", &N, &H);
	multiset<int> s;
	for(int i=0; i<N; i++){
		scanf("%lld", &a[i]);
		s.insert(a[i]);
		ll now=0;
		ll temp=1;
		for(auto p=s.end(); p!=s.begin();){
			p--;
//			printf("%d ", *(p));
			if(temp) now+=*(p);
			temp=1-temp;
		}
		if(now>H){
			printf("%d", i);
			N=0;
			break;
		}
//		printf("\n");
	}
	if(N) printf("%d", N);
}
