#include<stdio.h>
#include<algorithm>

long long c[250010];
long long l[250010], r[250010];

int main(void){
	printf("%d\n", int('a'));
	long long N, M;
	scanf("%lld %lld", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%lld", &c[i]);
	}
	for(int i=1; i<N; i++){
		l[i] = l[i-1] + (c[i]-c[i-1]+M)%M;
	}
	for(int i=N-2; i>=0; i--){
		r[i] = r[i+1] + (c[i+1]-c[i]+M)%M;
	}
	int ans=0, max=l[0]+r[0];
	for(int i=0; i<N; i++){
		if(max > std::max(l[i], r[i])) max = std::max(l[i], r[i]), ans=i;
	}
	printf("%d\n%d", ans+1, max);
}
