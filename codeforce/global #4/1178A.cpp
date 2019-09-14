#include<stdio.h>
#include<tuple>
#include<algorithm>

std::pair<int, int> a[1000001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i].first);
	long long int sum=0, sum2=0;
	for(int i=0; i<N; i++) sum += a[i].first, a[i].second=i+1;
	std::sort(a+1, a+N);
	int i=1;
	while(a[0].first*2 <= sum && i<N){
		if(a[0].first >= a[i].first*2) sum2 += a[i].first;
		else break;
		i++;
	}
	if(a[0].first+sum2<=sum/2) i=0;
	printf("%d\n", i);
	for(int j=0; j<i; j++) printf("%d ", a[j].second);
}
