#include<stdio.h>
#include<vector>
#include<algorithm>

int arr[100001];
std::vector<std::pair<int, int> > v;

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i]);
		v.push_back({arr[i], i});
	}
	std::sort(v.begin(), v.end());
	for(int i=0; i<K; i++){
		arr[v[N-1-i].second] = 0;
	}
	for(int i=0; i<N; i++) if(arr[i]) printf("%d ", arr[i]);
	for(int i=N-K; i<N; i++) printf("%d ",v[i]);
}
