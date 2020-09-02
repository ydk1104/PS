#include<stdio.h>
#include<stack>

int main(void){
	#define int long long
	int N, K;
	scanf("%d %lld", &N, &K);
	std::stack<int> stk;
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		stk.push(x);
		K -= x;
		if(K<0){
			printf("%d", i+1);
			return 0;
		}
	}
	for(int i=N; i; --i){
		K -= stk.top(); stk.pop();
		if(K<0){
			printf("%d", i);
			return 0;
		}
	}
}
