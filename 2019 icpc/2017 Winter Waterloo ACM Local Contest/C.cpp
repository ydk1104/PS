#include<stdio.h>
#include<vector>

std::vector<int> v[2];

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	if(K*2 < N){
		printf("0");
		return 0;
	}
//	if(N%2) v[1].push_back(N--);
	for(int i=1; i<=2*(N-K); i++){
		v[i%2].push_back(i);
	}
	for(int i=2*(N-K)+1; i<=N; i++){
		v[0].push_back(i);
	}
	for(int i=0; i<2; i++){
		for(auto j:v[i]) printf("%d ",j);
	}
}
