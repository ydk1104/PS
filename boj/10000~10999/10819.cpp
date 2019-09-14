#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;

int abs(int x){
	if(x>0) return x;
	return -x;
}

int main(void){
	int N, max=0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	do{
		int sum = 0;
		for(int i=0; i<N-1; i++){
			sum += abs(v[i] - v[i+1]);
		}
		max = (max>sum) ? max : sum;
	}
	while(next_permutation(v.begin(), v.end()));
	printf("%d", max);
	
}
