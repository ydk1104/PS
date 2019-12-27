#include<stdio.h>
#include<set>
#include<algorithm>
#define MAX 100000000

std::multiset<int> s;

int a[1000001];

int main(void){
	int N=1000000, K=N-2;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	K=N-K;
	std::sort(a, a+N);
	for(int i=1; i<K; i++) s.insert(a[i]-a[i-1]);
	int nMax, nMin;
	int ans=MAX;
	for(int i=K; i<N; i++){
		nMax = a[i-1] - a[i-K];
		nMin = *s.begin();
		ans=std::min(ans, nMax+nMin);
		s.erase(s.find(a[i-K+1]-a[i-K]));
		s.insert(a[i]-a[i-1]);
	}
	printf("%d", ans);
}
