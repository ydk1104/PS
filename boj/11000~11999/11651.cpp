#include<stdio.h>
#include<algorithm>

std::pair<int, int>p[100001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d %d", &p[i].second, &p[i].first);
	std::sort(p, p+N);
	for(int i=0; i<N; i++) printf("%d %d\n", p[i].second, p[i].first);
}
