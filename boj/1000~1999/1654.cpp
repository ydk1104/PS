#include<stdio.h>
#define ll long long

ll a[10001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	ll left=0, right=3000000000, ans=0;
	while(left<=right){
		ll mid = (left+right+1)/2;
		ll temp = 0;
		for(int i=0; i<N; i++) temp += a[i]/mid;
		if(temp>=M){
			ans = mid;
			left = mid+1;
		}
		else right=mid-1;
	}
	printf("%d\n", ans);
}
