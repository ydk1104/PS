#include<stdio.h>

int matrix[511][511];
int p[511][511];
int mod = 1e9+7;
int zero[511];
using ll = long long;
ll Fact[511];
bool cycle[511];

ll fact(int N){
	if(Fact[N]) return Fact[N];
	if(N==0) return 1;
//	if(N==-1) return 1;
	
	return Fact[N] = fact(N-1) * N % mod;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	
	
	ll ans = 1;
	for(int i=0; i<N; i++){
		if(cycle[i]) continue;
		ll min = 510, cnt = 0;
		for(int j=0; j<N; j++){
			for(int k=0; k<N; k++){
				p[i][j] += matrix[i][k] - matrix[j][k];
			}
			if(p[i][j] == 0) zero[i]++, cycle[i] = cycle[j] = true;
			if(p[i][j] == min) cnt++;
			else if(p[i][j] < min && p[i][j] > 0) min = p[i][j], cnt = 1;
			printf("%d ", p[i][j]);
		}
		if(cnt){
			ans *= cnt;
			ans %= mod;	
		}
		printf("\n");
		ans *= fact(zero[i]-1);
		ans %= mod;
	}
	
	printf("ans : ");
	printf("%lld", ans);
}
