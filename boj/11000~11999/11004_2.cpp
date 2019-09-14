#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int ans[5000001];

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		scanf("%d", &ans[i]);
	}
	nth_element(ans, ans+K-1, ans+N);
	printf("%d", ans[K-1]);
}
