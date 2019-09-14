#include<stdio.h>
#include<algorithm>
#define ll long long int

using namespace std;

int a[100001];
int N, K, A, B;

int BS(int left, int right, int ta){
	int mid = (left+right)/2;
	if(a[mid] == ta) return mid;
	if(left == right) return left;
	if(a[mid]>ta) return BS(left, mid-1, ta);
	return BS(mid+1, right, ta);
}

long long int find(int left, int right){
//	int cnt1 = BS(0, N-1, left);
	int* cnt1 = lower_bound (a, a+K, left);
//	printf("%d\n", cnt1);
//	int cnt2 = BS(0, N-1, right);
	int* cnt2 = lower_bound(a, a+K, right);
//	printf("%d %d %d\n", *cnt2, cnt1, cnt2);
	while(*cnt2 == right) cnt2++;
	return cnt2 - cnt1;
}

ll Burn(int left, int right){
	long long int cnt = find(left, right);
//	printf("%d %d %d\n", cnt, left, right);
	if(cnt == 0) return A;
	
	return cnt * B * (right-left+1);
}

ll usepower(int left, int right, ll power){
	if(left == right) return Burn(left, right);
	long long int cnt = find(left, right);
//	printf("%d %d %d\n", cnt, left, right);
	if(cnt==0) return A;
	ll temp = Burn(left, right);
	int mid = (left+right)/2;
	ll temp2 = usepower(left, mid, power) + usepower(mid+1, right, power);
	if(temp>temp2) return temp2;
	return temp;
}

int main(void){
	scanf("%d %d %d %d", &N, &K, &A, &B);
	for(int i=0; i<K; i++) scanf("%d", &a[i]);
	sort(a, a+K);
	ll ans = usepower(1, 1<<N, 0);
	printf("%lld", ans);
}
