#include<stdio.h>
#include<vector>
#include<algorithm>

int arr[200011];
int suml[200011];
int sumr[200011];

bool operator <(const std::pair<int, int> x, const int y){
	return x.first < y;
}

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		int r=0, b=0;
		for(int i=0; i<2*N; i++){
			scanf("%d", &arr[i]);
			if(arr[i] == 2) arr[i] = -1;
			if(~arr[i]) r++;
			else b++;
			suml[i] = sumr[i] = 0;
		}
		for(int i=0; i<2*N; i++) suml[i+1] = suml[i] + arr[i];
		for(int i=2*N-1; i>=0; i--) sumr[2*N-i] = sumr[2*N-i-1] + arr[i];
		std::vector<std::pair<int, int> > pl, pr;
		pl.emplace_back(-1, 0);
		for(int i=0; i<N; i++) pl.emplace_back(i, suml[i+1]);
		for(int i=0; i<N; i++) pr.emplace_back(sumr[i+1], i);
		pr.emplace_back(0, -1);
		int ans = 0;
		std::sort(pr.begin(), pr.end());
		for(const auto& i : pl){
			auto ub = std::upper_bound(pr.begin(), pr.end(), -i.second, [](const auto& x, const auto& y){
				return x < y.first;
			});
			ub--;
			if(ub >= pr.begin() && ub->first == -i.second) ans = std::max(ans, i.first+ub->second+2);
//			printf("ub : %d %d, ", ub->first, ub->second);
		}
		printf("%d\n", 2*N-ans);
	}
}
