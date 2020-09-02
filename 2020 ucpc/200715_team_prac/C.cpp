#include<stdio.h>

int bird[1000][1000];
int ans[1000000]; // 전역변수

int main() {
	long long Q, M;
	scanf("%lld %lld", &Q, &M);

	int t = 1;
	int i = 1, j = 1, k;
	while(bird[i][j] == 0) {
		bird[i][j] = t;
		ans[t] = i;
		k = i+j;
		k %= M; 
		i = j;
		j = k;
		t++;
	}
	int loop = t - bird[i][j];

	for(k=0;k<Q;k++) {
		long long int q; scanf("%lld", &q);
		printf("%d\n", q <= bird[i][j] ? ans[q] : ans[bird[i][j]+(q-bird[i][j])%loop]);
  // q를 입력받아서, q가 bird[i][j] 이하면 ans[q] 출력
  // bird[i][j] 초과면, q에서 bird[i][j]를 빼고 ans[bird[i][j]+q%loop] 출력
	}
}
