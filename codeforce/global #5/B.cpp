#include<stdio.h>
#include<vector>
#include<algorithm>

int arr[2][100001];
std::vector<int> v[2];
int in[100001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<2; i++){
		for(int j=0; j<N; j++){
			int x;
			scanf("%d", &x);
			v[i].push_back(x);
		}
	}
	std::reverse(v[0].begin(), v[0].end());
	std::reverse(v[1].begin(), v[1].end());
	int stk[100011] = {0,}, cnt=0;
	for(int i=0; i!=v[0].size(); i++){
		stk[cnt++] = i;
//		printf("%d ", v[0][i]);
		in[v[0][i]-1] = i;
	}
//	printf("\n");
	int max = -1, ans=0;
	for(auto i:v[1]){
//		printf("%d ", i);
		if(max > in[i-1]) ans++;
		else max = in[i-1];
	};
	printf("%d", ans);
}
