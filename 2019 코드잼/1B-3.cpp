#include<stdio.h>
#include<algorithm>

std::pair<int, int> x[100001];
struct segeTree{
	int C[300001];
	int D[300001];
	int ans[300001];
	int max;
	void fill(){
		for(int i=0; i<=max*2; i++){
			C[i]=D[i]=-200000;
			ans[i]=0;
		}
	}
	void update(int i, int x, int y, int K){
		i+=max;
		C[i]=x;
		D[i]=y;
		while(i){
			ans[i] = ans[i*2] + ans[i*2+1] + (std::abs(C[i]-D[i])<=K);
			i/=2;
			C[i] = std::max(C[i*2], C[i*2+1]);
			D[i] = std::max(D[i*2], D[i*2+1]);
		}
	}
}ST;

int main(void){
	int T;
	ST.max=(1<<3)-1;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		ST.fill();
		int N, K;
		scanf("%d %d", &N, &K);
		for(int i=1; i<=N; i++) scanf("%d", &x[i].first);
		for(int i=1; i<=N; i++) scanf("%d", &x[i].second);
		for(int i=1; i<=N; i++) ST.update(i, x[i].first, x[i].second, K);
		printf("Case #%d: %d\n", t, ST.ans[1]);
	}
}
