#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX 2000000000

using namespace std;

int N, M, K, a[300001], b[300001];
vector<pair<int, int> > v;

int main(void){
	scanf("%d %d %d", &N, &M, &K);
	long long int sum = 0;
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	for(int i=0; i<N; i++){
		pair<int, int> ii;
		ii.first = a[i];
		ii.second = i;
		v.push_back(ii); 
	}
	sort(v.begin(), v.end());
	for(int i=0; i<N-M*K; i++){
		a[v[i].second] = MAX;
	}
	int ans[300001];
	int cnt = 0;
	int row = 0;
	for(int i=0; i<N; i++){
		if(a[i] != MAX){
			sum += a[i];
			row++;
		}
		if(row>=M){
			ans[cnt++] = i+1;
			row = 0;
		}
	}
	printf("%lld\n", sum);
	for(int i=0; i<K-1; i++) printf("%d ", ans[i]);
}
