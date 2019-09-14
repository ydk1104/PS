#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int a[100001];
int b[100001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<N; i++) scanf("%d", &a[i]);
	for(int i=1; i<N; i++) scanf("%d", &b[i]);
	vector<pair<int, int> > v;
	for(int i=1; i<N; i++) v.push_back(make_pair(a[i], b[i]));
	sort(v.begin(), v.end());
}
