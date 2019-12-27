#include<stdio.h>
#include<set>
#include<tuple>

int a[200001];
int dp[200001];

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N, S;
		scanf("%d %d", &N, &S);
		for(int i=0; i<N; i++) scanf("%d", a+i);
		long long sum = 0;
		int ans = -1, max = -1, ans_max = -1;
		std::set<std::pair<int, int> > set;
		for(int l=0, r=0; r<N; r++){
			set.insert({a[r], r});
			max = set.rbegin()->second;
			sum += a[r];
			while(sum > S && (max == -1 || (sum-a[max] > S))){
				break;
			}
			int sz = set.size();
			if(sz > ans){
				if(sum <= S) ans = sz, ans_max = -1;
				else if(sum-a[max] <= S && sz-1 > ans) ans = set.size(), ans_max = max;
			}
		}
//		if(ans_max==-1) ans_max = 0;
		printf("%d\n", ans_max+1);
	}
}
