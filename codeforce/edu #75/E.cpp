#include<stdio.h>
#include<vector>
#include<algorithm>

const int MAX_N = 5000;

int num[MAX_N+1], temp[MAX_N+1];

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		for(int i=0; i<N; i++) num[i] = temp[i] = 0;
		std::vector<std::pair<int, int> > v;
		for(int i=0; i<N; i++){
			int x,y;
			scanf("%d %d", &x, &y);
			v.push_back({y,x});
			num[x]++;
		}
		std::sort(v.begin(), v.end());
		long long sum = 0;
		int left=0, right=num[0];
		while(left < right){
			left++;
			right += num[left];
		}
		std::vector<std::pair<int,int> > ans;
		for(auto i:v){
			if(right >= N) break;
			sum += i.first;
			if(i.second > right) temp[i.second]++, right++, ans.push_back({i.first, i.second});
			else { // do nothing?
				sum -= i.first;
			}
			while(left < right){
				left++;
				right += num[left]-temp[left];
			}
		}
		int sz = ans.size();
//		std::sort(ans.begin(), ans.end(), [](const std::pair<int, int>& x, const std::pair<int, int>& y){
//			return x.first > y.first;
//		});
		for(auto i:ans){
			temp[i.second]--;
			sz--;
			int left = 0, right = num[0] + sz;
			while(left < right){
				left++;
				right += num[left] - temp[left];
			}
			if(right >= N){
				sum -= i.first;
			}
			else{
				temp[i.second]++;
				sz++;
			}
		}
		printf("%d\n", sum);
	}
}
