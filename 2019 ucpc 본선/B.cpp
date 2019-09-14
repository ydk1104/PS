#include<stdio.h>
#include<algorithm>

int main(void){
	int N;
	scanf("%d", &N);
	while(N--){
		long long p,q,a,b,c,d;
		scanf("%lld %lld %lld %lld %lld %lld", &p, &q, &a, &b, &c, &d);
		q = (q/c)*d;
		long long ans = std::min(p,q);
		while(p<q){
			long long temp = (q-p)/(a+b);
			if(temp<=2) temp=1;
			p += temp*a;
			q -= temp*b;
			ans = std::max(ans, std::min(p,q));
		}
		while(q<p){
			long long temp = (p-q)/(a+b);
			if(temp<=2) temp=1;
			q += temp*b;
			p -= temp*a;
			ans = std::max(ans, std::min(p,q));
		}
		printf("%lld\n", ans);
	}
}
