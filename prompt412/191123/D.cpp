#include<stdio.h>
#include<map>

std::map<int, int> map;
int arr[30] = {2,};
int a[100001];

int main(void){
	for(int i=1; i<30; i++) arr[i] = arr[i-1] * 2;
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		a[i] = i+1;
		scanf("%d", a+i);
		map[a[i]]++;
	}
	long long ans = 0;
	for(int i=0; i<N; i++){
		for(auto& now:arr){
			const auto& find = map.find(now-a[i]);
			if(find != map.end())ans += find->second;
			if(a[i] == now-a[i]) ans--;
		}
	}
	printf("%lld", ans/2);
}
