#include<stdio.h>
#include<stack>
#include<tuple>

const int MOD = 1e9+7;
long long ans = 1;

std::stack<std::pair<int, int> > stk;
int read[100001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int prev=0;
	stk.push({0,-1});
	for(int i=0; i<M; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		if(y<prev){
			printf("0");
			return 0;
		}
		prev=y;
		stk.push({x,y});
	}
	int max = N;
	prev = stk.top().second;
	while(stk.size()){
		auto now = stk.top(); stk.pop();
		if(now.second != prev){
			ans *= nCr(max, prev);
			ans %= MOD;
			prev = now.second;
		}
		if(!read[now.first]){
			read[now.first]++;
			max--;
		}
		if(max < now.second){
			printf("0");
			return 0;
		}
	}
	printf("%d", ans);
}
