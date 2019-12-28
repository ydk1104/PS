#include<stdio.h>

int ans1(int N){ // O(N)
	int ans = 1;
	for(int i=1, plus=1; i<=N; i++) {
		ans += plus;
		if(i%3) plus++;
	}
	return ans;
}

int ans2(int N){ // O(1)
	int ans = (N)*(N+1)/2+1;
	int cnt = N%3; N/=3;
	ans -= (N)*(N-1)/2*3+cnt*N;
	return ans;
}

int main(void){
	int N;
	scanf("%d", &N);
	printf("%d", ans1(N));
}
