#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>

int main(void){
	int N;
	scanf("%d", &N);
	std::vector<int> v(N);
	for(int i=0; i<N; i++) scanf("%d", &v[i]);
	std::sort(v.begin(), v.end());
	int l=0, r=N-1;
	int max = abs(v[l]+v[r]), ans[2] = {v[l], v[r]};
	while(l<r){
		while(r>l+1 && abs(v[l]+v[r]) > abs(v[l]+v[r-1])) r--;
		if(max > abs(v[l]+v[r])){
			ans[0] = v[l];
			ans[1] = v[r];
			max = abs(v[l]+v[r]);
		}
		l++;
	}
	std::sort(ans, ans+2);
	printf("%d %d\n", ans[0], ans[1]);
}
