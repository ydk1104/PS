#include<stdio.h>
#include<vector>
#include<tuple>

int len, s[5001], start[5001], end[5001];
std::vector<std::pair<int, int> >ans;

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	scanf("%d", &len);
	for(int i=0; i<M; i++){
		scanf("%d", &s[i]);
	}
	for(int i=0; i<N; i++){
		scanf("%d %d", &start[i], &end[i]);
	}
	for(int i=N-1; i>=0; i--){
		int now = start[i];
		while(now != end[i]){
			int j = now;
			while(j>end[i] && s[j]+len >= now){
				j--;
			}
			if(now==j){
				printf("-1");
				return 0;
			}
			ans.push_back({now, j});
			now = j;
		}
	}
	printf("%d\n", ans.size());
	for(auto i:ans){
		printf("%d %d\n", i.first, i.second);
	}
	return 0;
}
