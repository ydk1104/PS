#include<stdio.h>
#include<numeric>
#include<vector>

long long fac[21];

void nthPermutation(int N, long long K){
	std::vector<int> check(N);
	std::iota(check.begin(), check.end(), 1);
	while(N--){
		long long now = (K-1) / fac[N];
		printf("%d ",check[now]);
		K -= now * fac[N];
		check.erase(check.begin()+now);
	}
}

void PerTonth(int N){
	std::vector<int> v(N);
	for(int i=0; i<N; i++) scanf("%d", &v[i]);
	std::vector<int> check(N);
	std::iota(check.begin(), check.end(), 1);
	long long ans = 1;
	for(int i=0; i<N; i++){
		int temp = 0;
		while(check[temp] < v[i]) temp++;
		ans += fac[N-i-1] * temp;
		check.erase(check.begin()+temp);
	}
	printf("%lld", ans);
}

int main(void){
	fac[0] = 1;
	for(int i=1; i<=20; i++) fac[i] = fac[i-1] * i;
	int N, type;
	scanf("%d %d", &N, &type);
	if(type==1){
		long long K;
		scanf("%lld", &K);
		nthPermutation(N, K);
	}
	else{
		PerTonth(N);
	}
}
