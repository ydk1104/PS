#include<stdio.h>
#include<queue>
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

class contest{
	public:
	long long int value[400000];
	long long int cost[400000];
	long long int nowD;
	long long int sum;
	long long int ans;
	priority_queue<long long int, vector<long long int> > pq;
	void solve(int left, int right){
		if(right>left) return;
		
	}
};

contest C;

int main(void){
	long long int N, money;
	scanf("%I64d %I64d", &N, &money);
	for(int i=0; i<N; i++){
		scanf("%I64d %I64d", &C.value[i], &C.cost[i]);
		if(i>0){
			C.pq.push(C.value[i] - C.value[i-1]);
			C.sum += C.nowD * C.nowD;
			C.nowD = C.pq.top();
			C.sum -= C.nowD * C.nowD;
		}
		C.sum += money-C.cost[i];
		C.ans = max(C.sum, C.ans);
	}
	C.solve(0, N-1);
	printf("%I64d", C.ans);
}
