#include<stdio.h>
#include<map>

int main(void){
	int N;
	std::map<long long,int> m[2];
	scanf("%d", &N);
	m[0][0] = 1;
	for(int i=0; i<N; i++){
		long long x;
		scanf("%lld", &x);
		m[(i+1)%2].clear();
		for(auto &j : m[i%2]){
//			printf("%d/%d ", j.first, j.second);
			m[(i+1)%2][j.first] += m[i%2][j.first];
			m[(i+1)%2][j.first+x] += m[i%2][j.first];
		}
//		printf("\n");
	}
	long long ans = 0;
	for(auto &j : m[N%2]){
		printf("%d/%d ", j.first, j.second);
		if(j.second >= 2) printf(" Fuck");
		if(j.second%2) ans ^= j.first;
	}
	printf("%lld", ans);
}
