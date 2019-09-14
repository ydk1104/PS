#include<stdio.h>
#include<algorithm>

using namespace std;

int N;
long long int a[300001];
long long int ans;

int main(void){
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%lld", &a[i]);
	sort(a, a+N);
	for(int i=0; i<N/2; i++){
		ans += (a[i] + a[N-i-1]) * (a[i] + a[N-i-1]);
	}
	printf("%lld", ans);
}
