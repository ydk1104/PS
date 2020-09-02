#include<stdio.h>
#include<vector>
#include<algorithm>
 
int a[200001];
int pos[200011];
 
int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	
	pos[N+1] = pos[N];
	
	long long sum = 0, ans = 1;
	std::vector<int> v;
	for(int i=N; i>N-K; i--){
		sum += i;
		v.push_back(pos[i]);
	}
	const int mod = 998244353;
	std::sort(v.begin(), v.end());
	for(int i=1; i<v.size(); i++){
		ans *= v[i] - v[i-1];
		ans %= mod;
	}
	printf("%lld %lld", sum, ans);
}
