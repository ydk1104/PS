#include<stdio.h>
#include<tuple>
#include<algorithm>
 
std::pair<int, int> arr[200001];
int N, M, K;
 
int go(int now){
	for(int i=now; i<N; i++){
		if(arr[i].first < arr[i-now].first + K) return 0;
	}
	return 1;
}
 
void print(int ans){
	for(int i=0; i<N; i++) arr[i].first = i;
	std::sort(arr, arr+N, [](std::pair<int, int>& x, std::pair<int, int>& y){return x.second<y.second;});
	for(int i=0; i<N; i++){
			printf("%d ", (arr[i].first)%ans+1);
	}
	printf("\n");
}
 
int main(void){
	scanf("%d %d %d", &N, &M, &K);
	K++;
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	std::sort(arr, arr+N);
	int left = 0, right = N+1;
	while(left < right){
		int mid = (left+right)/2;
		if(!go(mid)) left = mid+1;
		else right = mid;
	}
	for(int i=left-2; i<=left+3; i++){
		if(go(i)){
			printf("%d\n", i);
			print(i);
			break;
		}
	}
}
