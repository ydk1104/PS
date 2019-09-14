#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v;
int a[102];

int main(void){
	int N, M, L;
	scanf("%d %d %d", &N, &M, &L);
	for(int i=1; i<=N; i++) scanf("%d", &a[i]);
	a[N+1] = L;
	sort(a+1, a+N+1);
	for(int i=1; i<=N+1; i++){
		v.push_back(a[i]-a[i-1]);
	}
	int left=0, right=L;
	while(left<=right){
		int mid = (left+right+1)/2;
		int cnt = 0;
		for(auto i:v){
			if(i>=mid) cnt+=(i-1)/mid;
		}
//		printf("%d %d\n", mid, cnt);
		if(cnt<=M) right=mid-1;
		else left=mid+1;
	}
	printf("%d", left);
}
