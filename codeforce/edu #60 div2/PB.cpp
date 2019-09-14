#include<stdio.h>
#include<algorithm>
#define ll long long int

ll N, M, K, card[200001];

int main(void){
	scanf("%lld %lld %lld", &N, &M, &K);
	for(int i=0; i<N; i++) scanf("%lld", &card[i]);
	std :: sort(card, card+N);
	ll cycle = K+1;
	ll plus = card[N-1]*K + card[N-2];
	printf("%lld", (plus*(M/cycle))+card[N-1]*(M%cycle));
}
