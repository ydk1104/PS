#include<stdio.h>
#include<algorithm>
#define ll long long int

using namespace std;

int N, M, K, a[1000001], b[1000001];

int main(void){
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	for(int i=0; i<N-1; i++) b[i] = a[i+1] - a[i];
	sort(b, b+N-1);
	long long int sum = K;
	for(int i=0; i<N-K; i++) sum+=b[i];
	printf("%lld", sum);
}
