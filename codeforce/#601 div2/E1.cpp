#include<stdio.h>
#include<vector>
#include<algorithm>

int a[100001];
std::vector<int> v;
long long a_sum[100001];

inline long long func(int left, int right){
	long long temp = 0, lsum = 0, rsum = 0;
	rsum = a_sum[right] - a_sum[left];
//	printf("%d %d %d\n", left, right, rsum);
	for(long long i=left; i<right; i++){
		temp += (i-left) * a[i];
	}
	long long ans = temp;
	for(long long i=left; i<right; i++){
		lsum += a[i];
		rsum -= a[i];
		temp += lsum-rsum;
		if(ans > temp) ans = temp;
		else break;
	}
	return ans;
}

int main(void){
	long long N;
	scanf("%lld", &N);
	long long now = 0, ans = N+1, sum = 0, max = 0;
	for(int i=0; i<N; i++){
		scanf("%d", a+i);
		sum += a[i];
		a_sum[i+1] = a_sum[i] + a[i];
	}
	for(int i=2; i*i<=sum; i++){
		if(sum%i) continue;
		v.push_back(i);
		v.push_back(sum/i);
	}
	v.push_back(sum);
	if(sum>1){
		for(const auto& max : v){
			long long temp = 0, left = 0;
			for(int i=0; i<N; i++){
				now += a[i];
				if(now==max) now=0, temp += func(left, i+1), left=i+1;
				else if(!now) left = i+1;
			}
//			printf("%d %d\n\n", max, temp);
			ans = std::min(ans, temp);
		}
	}
	else ans = -1;
	printf("%lld", ans);
}
