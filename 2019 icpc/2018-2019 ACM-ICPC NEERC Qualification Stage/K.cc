#include<stdio.h>
#include<vector>
#include<algorithm>
 
std::vector<int> v;
 
int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	std::sort(v.begin(), v.end());
	int ans =0;
	while(N && v[(N-1)/2] >= M){
		if(N%2) ans++, N--;
		else ans+=2, N-=2;
 
	}
	printf("%d\n", ans);
	return 0;
}

