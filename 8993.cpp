#include<stdio.h>
#include<algorithm>

using namespace std;

int a[100001];
pair<int,int> p[100001]; 

int main(void){
	int N, M, L;
	scanf("%d %d %d", &N, &M, &L);
	for(int i=1; i<=N; i++) scanf("%d", &a[i]);
	for(int i=1; i<=M; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		p[i] = make_pair(x, y);
	}
	sort(a+1, a+N+1);
	a[0] = a[1];
	int ans=0;
	for(int i=1; i<=M; i++){
		int* x = lower_bound(a+1, a+N+1, p[i].first);
		int dis = min(abs((*x)-p[i].first), abs(*(x-1)-p[i].first)) + p[i].second;
//		printf("%d\n", dis);
//		printf("%d %d\n", abs((*x)-p[i].first), abs(*(x-1)-p[i].first));
		if(dis<=L) ans++;
	}
	printf("%d", ans);
}
