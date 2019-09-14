#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<map>

std::pair<int, int> a[300001];
std::map<int, int> m;
// max, extra, cnt

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d", &a[i].second, &a[i].first);
	}
	std::sort(a, a+N);
	m[a[0].first] = 1;
	int ans=0;
	for(auto i=a; i<a+N; i++{
		m[i->second] = m[i->second] + m[i->first];
		printf("%d %d %d %d\n", i->first, i->second, m[i->first], m[i->second]);
		if(i->second > (i+1)->first) ans += m[i->second];
	}
	printf("%d", ans);
}
