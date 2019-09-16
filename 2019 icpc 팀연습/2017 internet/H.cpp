#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<int> v[2];
int check;

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		int p = x==0;
		if(p){
			check++;
			continue;
		}
		v[x>0].push_back(x);
	}
	sort(begin(v[0]), end(v[0]));
	sort(begin(v[1]), end(v[1]), [](int x, int y){
		return x>y;
	});
//	for(auto i:v[0]) printf("%d ",i);
//	for(auto i:v[1]) printf("%d ",i);
	int ans = -2e9;
	if(v[0].size() >= 2){
		ans = std::max(ans, v[0][0] * v[0][1]);
	}
	if(v[0].size() && v[1].size()){
		ans = std::max(ans, v[0][v[0].size()-1] * v[1][v[1].size()-1]);
	}
	if(v[1].size() >= 2){
		ans = std::max(ans, v[1][0] * v[1][1]);
	}
	if(v[1].size() >= 3){
		ans = std::max(ans, v[1][0] * v[1][1] * v[1][2]);
	}
	if(v[1].size() >= 1 && v[0].size() >= 2){
		ans = std::max(ans, v[1][0] * v[0][0] * v[0][1]);
	}
	if(v[1].size() >= 2 && v[0].size() >= 1){
		ans = std::max(ans, v[1][v[1].size()-1] * v[1][v[1].size()-2] * v[0][v[0].size()-1]);
	}
	if(v[0].size() >= 3){
		ans = std::max(ans, v[0][v[0].size()-1] * v[0][v[0].size()-2] * v[0][v[0].size()-3]);
	}
	if(check) ans = std::max(ans, 0);
	printf("%d", ans);
}
