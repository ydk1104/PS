#include<stdio.h>
#include<vector>
#include<algorithm>

int main(void){
	int T;
	for(scanf("%d", &T);T--;){
		std::vector<int> v;
		int sum=0;
		for(int i=7; i--;){
			int x;
			scanf("%d", &x);
			if(x%2) continue;
			v.push_back(x);
			sum += x;
		}
		std::sort(v.begin(), v.end());
		printf("%d %d\n", sum, v[0]);
	}
}
