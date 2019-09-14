#include<stdio.h>
#include<algorithm>
#include<vector>
#include<tuple>

int a[300001];
int b[300001];
std::vector<std::pair<int, int> > v;
int sum[2];
int even[2][2];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N;i++){
		scanf("%d", &a[i]);
		sum[0] += a[i];
		v.push_back({a[i], i+1});
		even[0][a[i]%2]++;
	}
	for(int i=0; i<N; i++){
		scanf("%d", &b[i]);
		sum[1] += b[i];
		even[1][b[i]%2]++;
	}
	if(sum[0] != sum[1]){ //|| (even[0][0]!=even[1][0])){
		printf("NO");
		return 0;
	}
	sort(v.begin(), v.end());
	for(int i=0; i<N; i++){
		while(a[i]!=b[i]){
			if(a[i]>b[i]){
				
			}
		}
	}
}
