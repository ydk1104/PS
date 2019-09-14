#include "museum.h"

long long CountSimilarPairs(std::vector<int> B, std::vector<int> T, std::vector<int> G) {
	int MAX = 101;
	long long a[MAX+1]={0, }, b[MAX+1]={0, }, c[MAX+1]={0, }, ab[MAX*MAX+1] = {0, }, bc[MAX*MAX+1] = {0,}, ac[MAX*MAX+1] = {0,}, abc[MAX*MAX*MAX+1] = {0,};
	int N = B.size();
	for(int i=0; i<N; i++){
		int na = B[i], nb = T[i], nc = G[i];
		a[na]++, b[nb]++, c[nc]++;
		ab[na*MAX+nb]++, ac[na*MAX+nc]++, bc[nb*MAX+nc]++;
		abc[na*MAX*MAX + nb*MAX + nc]++;
	}
	long long ans = 0;
	for(int i=0; i<=MAX; i++){
		ans += (a[i] * (a[i]-1) / 2);
		ans += (b[i] * (b[i]-1) / 2);
		ans += (c[i] * (c[i]-1) / 2);
	}
	for(int i=0; i<=MAX*MAX; i++){
		ans -= (ab[i] * (ab[i]-1) / 2);
		ans -= (ac[i] * (ac[i]-1) / 2);
		ans -= (bc[i] * (bc[i]-1) / 2);
	}
	for(int i=0; i<=MAX*MAX*MAX; i++){
		ans += (abc[i] * (abc[i]-1) / 2);
	}
	return ans;
}
